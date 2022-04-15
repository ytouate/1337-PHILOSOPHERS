/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_funcs_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouate <ytouate@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 23:15:35 by ytouate           #+#    #+#             */
/*   Updated: 2022/04/15 23:17:53 by ytouate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	data_init(t_args *data, int ac, char **av)
{
	sem_unlink("fork");
	sem_unlink("print");
	
	data->print_sema = sem_open("print", O_CREAT, 0644, 1);
	data->num_of_philos = ft_atoi(av[1]);
	data->num_of_forks = data->num_of_philos;
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		data->meals_count = ft_atoi(av[5]);
	else
		data->meals_count = -1;
	data->forks = sem_open("fork", O_CREAT, 644, data->num_of_forks);
	if (data->num_of_forks == 0 || data->time_to_die == 0
		|| data->time_to_sleep == 0
		|| data->time_to_eat == 0 || data->meals_count == 0)
	{
		write(2, "Invalid Arguments\n", 19);
		return (0);
	}
	return (1);
}

t_data  *init_needed_data(t_args args, t_data **philos, int i)
{
	philos[i] = malloc(sizeof(t_data));
	philos[i]->id = i + 1;
	philos[i]->args = args;
	philos[i]->meals_track = 0;
	return (philos[i]);
}
