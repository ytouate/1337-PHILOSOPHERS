/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_funcs_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouate <ytouate@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 22:58:16 by ytouate           #+#    #+#             */
/*   Updated: 2022/04/16 03:11:03 by ytouate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	reset(void)
{
	printf("\033[0m");
}

void	green(void)
{
	printf("\033[0;32m");
}

void	red(void)
{
	printf("\033[31m");
}

void	put_time(t_data *philo)
{
	green();
	printf("%lld\n", philo->args.start_time);
	printf("%lld\t", current_timestamp() - philo->args.start_time);
	reset();
}

void	print_message(t_data *data, int act)
{
	sem_wait(data->args.print_sema);
	if (act == DIED)
	{
		put_time(data);
		printf("%d is died\n", data->id);
	}
	else if (act == EATING)
	{
		put_time(data);
		printf("%d is eating\n", data->id);
	}
	else if (act == SLEEPING)
	{
		put_time(data);
		printf("%d is sleeping\n", data->id);
	}
	else if (act == FORK)
	{
		put_time(data);
		printf("%d has taken is fork\n", data->id);
	}
	sem_post(data->args.print_sema);
}
