/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_funcs_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouate <ytouate@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 22:58:16 by ytouate           #+#    #+#             */
/*   Updated: 2022/04/15 23:30:38 by ytouate          ###   ########.fr       */
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

void	print_message(t_data *data, int act)
{
	sem_wait(data->args.print_sema);
	if (act == DIED)
	{
		red();
		printf("philo %d is died\n", data->id);
		reset();
	}
	else if (act == EATING)
	{
		green();
		printf("philo %d is eating\n", data->id);
		reset();
	}
	else if (act == SLEEPING)
		printf("philo %d is sleeping\n", data->id);
	else if (act == FORK)
		printf("philo %d has taken is fork\n", data->id);
	sem_post(data->args.print_sema);
}
