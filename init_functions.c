/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouate <ytouate@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 11:54:49 by ytouate           #+#    #+#             */
/*   Updated: 2022/04/07 22:08:54 by ytouate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_think(t_data	philo);
void	ft_pick_forks(t_data *philo);
void	ft_put_down_forks(t_data *philo);
void	ft_eat(t_data philo);
void	ft_sleep(t_data philo);

void	*ft_philosophers(void *a)
{
	t_data	*data = a;
	while (1)
	{
		pthread_mutex_lock(data->fork);
		printf("philo %d has taken a fork\n", data->j);
		pthread_mutex_lock(data->next_fork);
		printf("philo %d has taken a fork\n", data->j);
		usleep(data->args.time_to_eat * 1000);
		printf("philo %d is eating\n", data->j);
		pthread_mutex_unlock(data->fork);
		pthread_mutex_unlock(data->next_fork);
		usleep(data->args.time_to_sleep * 1000);
		printf("philo %d is sleeping\n", data->j);
	}
	return (NULL);
}

void	data_init(t_args *data, int ac, char **av)
{
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
		data->meals_count = -1;
}

t_data **put_fork(t_args arg)
{
	int i = 0;
	t_data **philos = malloc(sizeof(t_data *) * arg.num_of_philos);
	
	while (i < arg.num_of_philos)
	{
		philos[i] = malloc(sizeof(t_data));
		philos[i]->fork = malloc(sizeof(pthread_mutex_t));
		pthread_mutex_init(philos[i]->fork, NULL);
		i++;
	}
	return (philos);
}
t_data **put_next_fork(t_data **data, t_args args)
{
	int i= 0;
	while (i < args.num_of_philos)
	{
		data[i]->next_fork = data[(i + 1) % args.num_of_philos]->fork;
		i++;
	}
	return (data);
}
t_data	**init_philos(t_args	arg)
{
	int				i;
	t_data			**data;
	pthread_t		*p;
	
	
	i = 0;
	
	data = put_fork(arg);
	data = put_next_fork(data, arg);
	p = malloc(sizeof(pthread_t) * arg.num_of_philos);
	if (!data || !p)
		exit(write(2, "an error occured allocating memory\n", 36));
	while (i < arg.num_of_philos)
	{
		data[i] = init_needed_data(data, arg, i);
		if (pthread_create(&p[i], NULL, ft_philosophers, data[i]) == -1)
			exit(write(2, "an error occured while creating threads\n", 41));
		i++;
		usleep(100);
	}
	join_philos(p, arg);
	return (data);
}

t_data	*init_needed_data(t_data **data, t_args args, int i)
{
	data[i]->args = args;
	data[i]->j = i + 1;
	return (data[i]);
}
