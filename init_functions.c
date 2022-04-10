/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouate <ytouate@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 11:54:49 by ytouate           #+#    #+#             */
/*   Updated: 2022/04/10 00:17:35 by ytouate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	data_init(t_args *data, int ac, char **av)
{
	data->num_of_philos = ft_atoi(av[1]);
	if (data->num_of_philos == 0)
	{
		write(2, "Invalid number of philosophers\n", 32);
		return (0);
	}
	data->num_of_forks = data->num_of_philos;
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		data->meals_count = ft_atoi(av[5]);
	else
		data->meals_count = -1;
	return (1);
}

t_data	**put_fork(t_args arg)
{
	int		i;
	t_data	**philos;

	philos = malloc(sizeof(t_data *) * arg.num_of_philos);
	i = 0;
	while (i < arg.num_of_philos)
	{
		philos[i] = malloc(sizeof(t_data));
		philos[i]->fork = malloc(sizeof(pthread_mutex_t));
		pthread_mutex_init(philos[i]->fork, NULL);
		i++;
	}
	return (philos);
}

t_data	**put_next_fork(t_data **data, t_args args)
{
	int	i;

	i = 0;
	while (i < args.num_of_philos)
	{
		data[i]->next_fork = data[(i + 1) % args.num_of_philos]->fork;
		i++;
	}
	return (data);
}

int	check_meals (t_data **philos)
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

int check_death(t_data **philos)
{
	int i;
	int num;

	num = philos[0]->args.num_of_philos;
	if (num == 1)
		return (0);
	i = 0;
	while (i < num)
	{
		if (philos[i]->last_meal_time == 0)
			return (1);
		if (current_timestamp() - philos[i]->last_meal_time >= (*philos)->args.time_to_die)
			return (0);
		i++;
	}
	return (1);
}
t_data	**init_philos(t_args	arg)
{
	int				i;
	t_data			**data;
	pthread_t		*p;

	i = 0;
	data = put_fork(arg);
	data = put_next_fork(data, arg);
	p = malloc(sizeof(pthread_t) * arg.num_of_philos);
	if (!p)
		return (0);
	while (i < arg.num_of_philos)
	{
		data[i] = init_needed_data(data, arg, i);
		if (pthread_create(&p[i], NULL, ft_philosophers, data[i]) == -1)
		{
			write(2, "an error occured while creating threads\n", 41);
			return (0);
		}
		i++;
		usleep(100);
	}
	while (1)
	{
		if (check_meals(data) == 1)
		{
			print_message(*data, END);
			return (0); 
		}
		if (!check_death(data))
		{
			print_message(*data, DIED);
			return (0);
		}
	}
	return (data);
}

t_data	*init_needed_data(t_data **data, t_args args, int i)
{
	data[i]->args = args;
	data[i]->meals_eaten = 0;
	data[i]->j = i + 1;
	return (data[i]);
}

/* handle the 0 case in the sixth argument */