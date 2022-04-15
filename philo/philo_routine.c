/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouate <ytouate@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 14:41:37 by ytouate           #+#    #+#             */
/*   Updated: 2022/04/15 15:06:26 by ytouate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	current_timestamp(void)
{
	struct timeval	current_time;
	long long		miliseconds;

	gettimeofday(&current_time, NULL);
	miliseconds = (current_time.tv_sec * 1000) + (current_time.tv_usec / 1000);
	return (miliseconds);
}

void	ft_eat(t_data *philo)
{
	pthread_mutex_lock(philo->fork);
	print_message(philo, FORK);
	pthread_mutex_lock(philo->next_fork);
	print_message(philo, FORK);
	philo->last_meal_time = current_timestamp();
	print_message(philo, EATING);
	ft_usleep(philo->args.time_to_eat);
	philo->meals_eaten += 1;
	pthread_mutex_unlock(philo->fork);
	pthread_mutex_unlock(philo->next_fork);
}

void	*ft_philosophers(void *a)
{
	t_data		*data;

	data = a;
	while (1)
	{
		ft_eat(data);
		print_message(data, SLEEPING);
		ft_usleep(data->args.time_to_sleep);
		print_message(data, THINKING);
	}
	return (NULL);
}
