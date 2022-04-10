/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_funcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouate <ytouate@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 14:39:50 by ytouate           #+#    #+#             */
/*   Updated: 2022/04/10 13:35:04 by ytouate          ###   ########.fr       */
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

void	put_time(void)
{
	green();
	printf("%lld\t", current_timestamp());
	reset();
}

void	print_message_2(t_data *philo, int act)
{
	if (act == THINKING)
	{
		put_time();
		printf("philo %d is thinking\n", philo->j);
	}
	else if (act == END)
	{
		put_time();
		printf("the simulation ends\n");
	}
	else if (act == DIED)
	{
		put_time();
		printf("philo %d is died\n", philo->j);
	}
}

void	print_message(t_data *philo, int act)
{
	static pthread_mutex_t	lock = PTHREAD_MUTEX_INITIALIZER;

	pthread_mutex_lock(&lock);
	if (act == FORK)
	{
		put_time();
		printf("philo %d has taken a fork\n", philo->j);
	}
	else if (act == EATING)
	{
		put_time();
		printf("philo %d is eating\n", philo->j);
	}
	else if (act == SLEEPING)
	{
		put_time();
		printf("philo %d is sleeping\n", philo->j);
	}
	print_message_2(philo, act);
	pthread_mutex_unlock(&lock);
}
