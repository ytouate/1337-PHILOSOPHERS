/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouate <ytouate@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 14:41:37 by ytouate           #+#    #+#             */
/*   Updated: 2022/04/09 14:50:03 by ytouate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	current_timestamp(void)
{
	struct timeval	current_time;
	long long		miliseconds;

	gettimeofday(&current_time, NULL);
	miliseconds = current_time.tv_sec * 1000LL + current_time.tv_usec / 1000;
	return (miliseconds);
}

void	*ft_philosophers(void *a)
{
	t_data	*data;

	data = a;
	while (1)
	{
		pthread_mutex_lock(data->fork);
		print_message(data, FORK);
		pthread_mutex_lock(data->next_fork);
		print_message(data, FORK);
		print_message(data, EATING);
		usleep(data->args.time_to_eat * 1000);
		pthread_mutex_unlock(data->fork);
		pthread_mutex_unlock(data->next_fork);
		print_message(data, SLEEPING);
		usleep(data->args.time_to_sleep * 1000);
	}
	return (NULL);
}
