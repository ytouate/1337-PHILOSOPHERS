/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_funcs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouate <ytouate@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 13:54:01 by ytouate           #+#    #+#             */
/*   Updated: 2022/04/18 23:28:57 by ytouate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_meals(t_data **philos)
{
	int		i;
	int		meals;
	int		num;
	int		flag;

	flag = 0;
	meals = philos[0]->args.meals_count;
	if (meals == -1)
		return (0);
	num = philos[0]->args.num_of_philos;
	i = -1;
	while (++i < num)
	{
		if (philos[i]->meals_eaten >= meals)
			flag += 1;
	}
	if (flag == num)
		return (1);
	else
		return (0);
}

int	check_death(t_data **philos)
{
	int			i;
	int			num;
	long long	res;

	num = philos[0]->args.num_of_philos;
	if (num == 1)
		return (usleep((*philos)->args.time_to_die * 1000));
	i = 0;
	while (i < num)
	{
		res = current_timestamp() - philos[i]->last_meal_time;
		if (philos[i]->last_meal_time != 0)
		{
			if (res > (*philos)->args.time_to_die)
				return (0);
		}
		i++;
	}
	return (1);
}

void	red(void)
{
	printf("\033[31m");
}

int	ft_end(t_data **data)
{
	while (1)
	{
		if (check_meals(data) == 1)
		{
			pthread_mutex_lock((*data)->args.print_lock);
			put_time(*data);
			printf("the simulation has ended all philos ate %d meals\n",
				(*data)->args.meals_count);
			free(data);
			return (0);
		}
		if (!check_death(data))
		{
			pthread_mutex_lock((*data)->args.print_lock);
			green();
			put_time(*data);
			red();
			printf("%d is died\n", (*data)->j);
			free(data);
			return (0);
		}
	}
}
