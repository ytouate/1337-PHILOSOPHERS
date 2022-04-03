/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouate <ytouate@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 11:54:49 by ytouate           #+#    #+#             */
/*   Updated: 2022/04/03 21:59:34 by ytouate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_think(t_single_philo	philo);
void	ft_pick_forks(t_single_philo philo);
void	ft_eat(t_single_philo philo);
void	ft_sleep(t_single_philo philo);

void	*ft_philosophers(void *a)
{
	t_single_philo	*temp;

	temp = a;
	return (temp);
}

void	data_init(t_args *data, int ac, char **av)
{
	if (ac != 5 && ac != 6)
		exit(write(2, "Invalid Arguments\n", 19));
	data->num_of_philos = ft_atoi(av[1]);
	if (data->num_of_philos == 0)
		exit(write(2, "Invalid number of philosophers\n", 32));
	data->num_of_forks = data->num_of_philos;
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		data->meals_count = ft_atoi(av[5]);
	else
		data->meals_count = INT_MIN;
}

t_fork	*init_forks(t_args	arg)
{
	t_fork			*forks;
	int				i;

	i = 0;
	forks = malloc(sizeof(t_fork) * arg.num_of_forks);
	if (pthread_mutex_init(&forks[i].id, NULL) == -1)
		exit(write(2, "an error occured while initializing a mutex\n", 45));
	while (i < arg.num_of_forks)
	{
		if (pthread_mutex_init(&forks[i].id, NULL) == -1)
			exit(write(2, "an error occured while initializing a mutex\n", 45));
		forks[i].index = i;
		i++;
	}
	return (forks);
}

t_single_philo	*init_philos(t_args	arg, t_fork *f)
{
	int				i;
	t_single_philo	*n;

	i = 0;
	n = malloc(sizeof(t_single_philo) * arg.num_of_philos);
	if (!n)
		exit(write(2, "an error occured allocating memory\n", 36));
	memset(n, 0, sizeof(t_single_philo) * arg.num_of_forks);
	while (i < arg.num_of_philos)
	{
		n[i] = init_needed_data(f, arg, n, i);
		if (pthread_create(&n[i].p.id, NULL, ft_philosophers, &n[i]) == -1)
			exit(write(2, "an error occured while creating threads\n", 41));
		i++;
	}
	join_philos(n, arg);
	return (n);
}

t_single_philo	init_needed_data(t_fork *f, t_args args,
				t_single_philo	*philo, int i)
{
	philo[i].d = args;
	philo[i].p.stats.is_eating = 0;
	philo[i].p.stats.is_hungry = 0;
	philo[i].p.stats.is_sleeping = 0;
	philo[i].p.stats.is_thinking = 0;
	philo[i].p.left_fork = ((i + 1) % args.num_of_forks);
	philo[i].p.right_fork = i;
	philo[i].f = f[i];
	philo[i].f.id = f[i].id;
	philo[i].j = i;
	philo[i].p.index = i + 1;
	philo[i].f.index = i + 1;
	return (philo[i]);
}
