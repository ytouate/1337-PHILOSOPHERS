/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouate <ytouate@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 01:49:23 by ytouate           #+#    #+#             */
/*   Updated: 2022/04/15 23:22:43 by ytouate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_end(t_data *data)
{
	if (current_timestamp() - data->last_meal_time > data->args.time_to_die)
	{
		sem_wait(data->args.print_sema);
		printf("philo dies\n");
		exit(0);
	}
	else if (data->meals_track >= data->args.meals_count
		&& data->args.meals_count != -1)
	{
		sem_wait(data->args.print_sema);
		kill(getpid(), SIGINT);
		kill(getppid(), SIGINT);
		printf("the simulation ends\n");
	}
}

void	routine(t_data *data)
{
	while (1)
	{
		sem_wait(data->args.forks);
		print_message(data, FORK);
		sem_wait(data->args.forks);
		print_message(data, FORK);
		data->last_meal_time = current_timestamp();
		print_message(data, EATING);
		usleep(data->args.time_to_eat * 1000);
		data->meals_track += 1;
		sem_post(data->args.forks);
		sem_post(data->args.forks);
		usleep(data->args.time_to_sleep * 1000);
		print_message(data, SLEEPING);
		print_message(data, THINKING);
		ft_end(data);
	}
}

void	ft_wait(int ac, pid_t *pid, t_args args)
{
	int		i;

	i = -1;
	if (ac == 6)
		while (++i < args.num_of_philos)
			waitpid(pid[i], NULL, 0);
	else
		waitpid(-1, NULL, 0);
}

void	start_routine(int ac, t_args args)
{
	int			i;
	pid_t		*pid;
	t_data		**philos;

	i = -1;
	philos = malloc(sizeof(t_data *) * args.num_of_philos);
	pid = malloc(sizeof(pid_t) * args.num_of_philos);
	while (++i < args.num_of_philos)
	{
		philos[i] = init_needed_data(args, philos, i);
		pid[i] = fork();
		if (pid[i] == 0)
		{
			philos[i]->start_time = current_timestamp();
			routine(philos[i]);
			exit(EXIT_SUCCESS);
		}
	}
	ft_wait(ac, pid, args);
}

int	main(int ac, char **av)
{
	t_args		args;

	if (check_args(ac, av))
		if (data_init(&args, ac, av))
			start_routine(ac, args);
}
