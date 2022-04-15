/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouate <ytouate@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 01:49:23 by ytouate           #+#    #+#             */
/*   Updated: 2022/04/15 02:14:28 by ytouate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	ft_atoi(const char *str)
{
	int				i;
	int				sign;
	unsigned long	result;

	i = 0;
	sign = 1;
	result = 0;
	while ((str[i] == ' ') || (str[i] == '\t') || (str[i] == '\r')
		|| (str[i] == '\n') || (str[i] == '\v') || (str[i] == '\f'))
		i++;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			sign = -1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (result > 9223372036854775807)
		{
			if (sign == -1)
				return (0);
			return (-1);
		}
		result = (10 * result) + str[i++] - '0';
	}
	return ((((int)result) * sign));
}

int	is_int(char *s)
{
	int	i;

	i = -1;
	while (s[++i])
	{
		if (!(s[i] >= '0' && s[i] <= '9'))
		{
			if (s[i] == '-')
				return (-1);
			return (0);
		}
	}
	return (1);
}

int	check_args(int ac, char **av)
{
	int	i;

	i = 0;
	if (ac == 5 || ac == 6)
	{
		while (++i < ac)
		{
			if (is_int(av[i]) == 0 || av[i][0] == '\0')
			{
				write(2, "some or all arguments are not integers\n", 40);
				return (0);
			}
			else if (is_int(av[i]) == -1)
			{
				write(2, "args cannot be negative\n", 25);
				return (0);
			}
		}
	}
	else
	{
		exit(write(1, "The number of arguments is invalid\n", 36));
		return (0);
	}
	return (1);
}

int	data_init(t_args *data, int ac, char **av)
{
	data->num_of_philos = ft_atoi(av[1]);
	data->num_of_forks = data->num_of_philos;
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		data->meals_count = ft_atoi(av[5]);
	else
		data->meals_count = -1;
	if (data->num_of_forks == 0 || data->time_to_die == 0
		|| data->time_to_sleep == 0
		|| data->time_to_eat == 0 || data->meals_count == 0)
	{
		write(2, "Invalid Arguments\n", 19);
		return (0);
	}
	return (1);
}

void routine(t_data *data)
{
	while (1)
	{
		sem_wait(data->args.forks);
		printf("philo %d has taken a fork\n", data->id);
		sem_wait(data->args.forks);
		printf("philo %d has taken a fork\n", data->id);
		data->last_meal_time = current_timestamp();
		usleep(data->args.time_to_eat * 1000);
		printf("philo %d is eating\n", data->id);
		sem_post(data->args.forks);
		sem_post(data->args.forks);
		usleep(data->args.time_to_sleep * 1000);
		printf("philo %d is sleeping\n", data->id);
		printf("philo %d is thinking\n", data->id);	
	}
}

long long	current_timestamp(void)
{
	struct timeval	current_time;
	long long		miliseconds;

	gettimeofday(&current_time, NULL);
	miliseconds = (current_time.tv_sec * 1000) + (current_time.tv_usec / 1000);
	return (miliseconds);
}

void	ft_usleep(long long desired_time)
{
	long long start_time;
	long long end_time;
	start_time = current_timestamp();
	end_time = start_time + desired_time;
	while (start_time < end_time)
	{
		usleep(200);
	}
	// usleep(desire_time * 98 / 100);
}

int main(int ac, char **av)
{
	t_args		args;
	t_data		**philos;
	sem_t		*forks;
	int			i;
	pid_t		*pid;
	int j = 	1;
	i = 0;
	
	if (check_args(ac, av))
	{
		if (data_init(&args, ac, av))
		{
			sem_unlink("fork");
			philos = malloc(sizeof(t_data *)  *args.num_of_philos);
			pid = malloc(sizeof(pid_t) * args.num_of_philos);
			args.forks = sem_open("fork", O_CREAT, 777, args.num_of_forks);
			while (i < args.num_of_philos)
			{
				philos[i] = malloc(sizeof(t_data));
				pid[i] = fork();
				philos[i]->id = i + 1;
				philos[i]->pid = pid[i];
				philos[i]->args = args;
				if (pid[i] == 0)
				{
					philos[i]->start_time = current_timestamp();
					routine(philos[i]);
					exit(EXIT_SUCCESS);
				}
				i++;
			}
			int i = -1;
			while (++i < args.num_of_philos)
				waitpid(pid[i], NULL, 0);
		}
	}
}