/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouate <ytouate@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 22:58:13 by ytouate           #+#    #+#             */
/*   Updated: 2022/04/18 15:09:54 by ytouate          ###   ########.fr       */
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
	long long	end_time;

	end_time = current_timestamp() + desired_time;
	while (current_timestamp() < end_time)
		usleep(100);
}

void	ft_wait(int ac, pid_t *pid, t_args args)
{
	int		i;

	i = -1;
	if (ac == 6)
	{
		while (++i < args.num_of_philos)
		{
			if (waitpid(pid[i], NULL, 0) == -1)
				exit(1);
		}
	}
	else
		if (waitpid(-1, NULL, 0) == -1)
			exit(1);
	free(pid);
}
