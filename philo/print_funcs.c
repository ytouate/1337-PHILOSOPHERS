/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_funcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouate <ytouate@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 14:39:50 by ytouate           #+#    #+#             */
/*   Updated: 2022/04/17 00:57:24 by ytouate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	reset(void)
{
	printf("\033[0m");
}

void	green(void)
{
	printf("\033[0;32m");
}

void	put_time(t_data *philo)
{
	(void)philo;
	green();
	printf("%lld:\t", current_timestamp() - philo->args.start_time);
	reset();
}

void	print_message(t_data *philo, int act)
{
	pthread_mutex_lock(philo->args.print_lock);
	if (act == FORK)
	{
		put_time(philo);
		printf("%d has taken a fork\n", philo->j);
	}
	else if (act == EATING)
	{
		put_time(philo);
		printf("%d is eating\n", philo->j);
	}
	else if (act == SLEEPING)
	{
		put_time(philo);
		printf("%d is sleeping\n", philo->j);
	}
	if (act == THINKING)
	{
		put_time(philo);
		printf("%d is thinking\n", philo->j);
	}
	pthread_mutex_unlock(philo->args.print_lock);
}
