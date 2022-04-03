/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouate <ytouate@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 11:54:49 by ytouate           #+#    #+#             */
/*   Updated: 2022/04/03 11:57:35 by ytouate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	*routine(void *a)
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
	pthread_mutex_t	*p;
	int				flag;
	int				i;

	i = 0;
	forks = malloc(sizeof(t_fork) * arg.num_of_forks);
	p = malloc(sizeof(pthread_mutex_t) * arg.num_of_forks);
	if (!p || !forks)
		return (NULL);
	flag = pthread_mutex_init(&p[i], NULL);
	if (flag == -1)
		exit(write(2, "an error occured while initializing a mutex\n", 45));
	forks[i].id = p[i];
	forks[i].index = i + 1;
	arg.num_of_forks--;
	while (arg.num_of_forks)
	{
		flag = pthread_mutex_init(&p[++i], NULL);
		if (flag == -1)
			exit(write(2, "an error occured while initializing a mutex\n", 45));
		forks[i].id = p[i];
		forks[i].index = i + 1;
		arg.num_of_forks--;
	}
	return (forks);
}

t_single_philo	*init_philos(t_args	arg, t_fork *f)
{
	int				i;
	int				flag;
	t_single_philo	*n;

	i = 0;
	n = malloc(sizeof(t_single_philo) * arg.num_of_philos);
	if (!n)
		exit(write(2, "an error occured allocating memory\n", 36));
	n[i] = init_needed_data(f, arg, n, i);
	flag = pthread_create(&n->p.id, NULL, routine, &n[i]);
	if (flag == -1)
		exit(write(2, "an error occured while creating threads\n", 41));
	arg.num_of_philos--;
	while (arg.num_of_philos)
	{
		++i;
		n[i] = init_needed_data(f, arg, n, i);
		flag = pthread_create(&n->p.id, NULL, routine, &n[i]);
		if (flag == -1)
			exit(write(2, "an error occured while creating threads\n", 41));
		arg.num_of_philos--;
	}
	return (n);
}

t_single_philo	init_needed_data(t_fork *f, t_args args, t_single_philo	*philo, int i)
{
	philo[i].d = args;
	philo[i].f = f[i];
	philo[i].f.id = f[i].id;
	philo[i].j = i;
	philo[i].p.index = i + 1;
	philo[i].f.index = i + 1;
	return (philo[i]);
}
