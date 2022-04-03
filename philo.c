/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouate <ytouate@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 11:44:37 by ytouate           #+#    #+#             */
/*   Updated: 2022/04/02 19:19:36 by ytouate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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


void *routine(void *a)
{
	single_philo *temp = a;
	printf("hello from philo %d\n", temp->j);
	return (a);
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

t_philo	*init_philos(t_args	arg, t_fork *f)
{
	int		i;
	t_philo	*philos;
	pthread_t	*p;
	single_philo	*n;

	n = malloc(sizeof(single_philo));
	int flag;
	i = 0;
	n->d = arg;
	n->f = f[i];
	n->j = i;
	
	philos = malloc(sizeof(t_philo) * arg.num_of_philos);
	p = malloc(sizeof(pthread_t) * arg.num_of_philos);
	if (!p || !philos)
		exit(1);
	n->p.index = i + 1;
	flag = pthread_create(&n->p.id, NULL, routine, n);
	if (flag == -1)
		exit(write(2, "an error occured while creating threads\n", 41));
	philos[i].index = i + 1;
	philos[i].id = n->p.id;
	arg.num_of_philos--;
	while (arg.num_of_philos)
	{
		n = malloc(sizeof(single_philo));
		n->j = ++i;
		n->p.index = i + 1;
		flag = pthread_create(&n->p.id, NULL, routine, n);
		if (flag == -1)
			exit(write(2, "an error occured while creating threads\n", 41));
		philos[i].index = i + 1;
		philos[i].id = n->p.id;
		arg.num_of_philos--;
	}
	return (philos);
}

void join_philos(t_philo	*philos, t_args data)
{
	int	i;

	i = -1;
	while (++i < data.num_of_forks)
		pthread_join(philos[i].id, NULL);
}

int	main(int ac, char **av)
{
	t_philo			*philos;
	t_fork			*forks;
	t_args			data;

	check_args(ac, av);
	data_init(&data, ac, av);
	forks = init_forks(data);
	philos = init_philos(data, forks);
	join_philos(philos, data);
}
