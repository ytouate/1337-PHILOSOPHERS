/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouate <ytouate@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 11:54:49 by ytouate           #+#    #+#             */
/*   Updated: 2022/04/16 03:00:04 by ytouate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_data	**put_fork(t_args arg)
{
	int		i;
	t_data	**philos;

	philos = malloc(sizeof(t_data *) * arg.num_of_philos);
	i = 0;
	while (i < arg.num_of_philos)
	{
		philos[i] = malloc(sizeof(t_data));
		philos[i]->fork = malloc(sizeof(pthread_mutex_t));
		pthread_mutex_init(philos[i]->fork, NULL);
		i++;
	}
	return (philos);
}

t_data	**put_next_fork(t_data **data, t_args args)
{
	int	i;

	i = 0;
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
	arg.start_time = current_timestamp();
	if (!p)
		return (0);
	while (i < arg.num_of_philos)
	{
		data[i] = init_needed_data(data, arg, i);
		data[i]->args.start_time = current_timestamp();
		if (pthread_create(&p[i], NULL, ft_philosophers, data[i]) == -1)
		{
			write(2, "an error occured while creating threads\n", 41);
			return (0);
		}
		i++;
		usleep(50);
	}
	if (ft_end(data) == 0)
		return (0);
	return (NULL);
}

t_data	*init_needed_data(t_data **data, t_args args, int i)
{
	data[i]->args = args;
	data[i]->meals_eaten = 0;
	data[i]->j = i + 1;
	return (data[i]);
}
