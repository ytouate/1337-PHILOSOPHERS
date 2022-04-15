/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouate <ytouate@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 22:58:13 by ytouate           #+#    #+#             */
/*   Updated: 2022/04/15 23:43:46 by ytouate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

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
	long long	start_time;
	long long	end_time;

	start_time = current_timestamp();
	end_time = start_time + desired_time;
	while (start_time < end_time)
	{
		usleep(100);
		start_time = current_timestamp();
	}
}
