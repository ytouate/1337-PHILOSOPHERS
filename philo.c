/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouate <ytouate@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 11:44:37 by ytouate           #+#    #+#             */
/*   Updated: 2022/04/12 20:35:10 by ytouate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_int(char *s)
{
	int	i;

	i = -1;
	while (s[++i])
	{
		if (!(s[i] >= '0' && s[i] <= '9'))
		{
			if (s[i] == '-')
				return (-1);
			return (0);
		}
	}
	return (1);
}

int	check_args(int ac, char **av)
{
	int	i;

	i = 0;
	if (ac == 5 || ac == 6)
	{
		while (++i < ac)
		{
			if (is_int(av[i]) == 0 || av[i][0] == '\0')
			{
				write(2, "some or all arguments are not integers\n", 40);
				return (0);
			}
			else if (is_int(av[i]) == -1)
			{
				write(2, "args cannot be negative\n", 25);
				return (0);
			}
		}
	}
	else
	{
		exit(write(1, "The number of arguments is invalid\n", 36));
		return (0);
	}
	return (1);
}

int	data_init(t_args *data, int ac, char **av)
{
	data->print_lock = malloc (sizeof(pthread_mutex_t));
	pthread_mutex_init(data->print_lock, NULL);
	data->num_of_philos = ft_atoi(av[1]);
	data->num_of_forks = data->num_of_philos;
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		data->meals_count = ft_atoi(av[5]);
	else
		data->meals_count = -1;
	if (data->num_of_forks == 0 || data->time_to_die == 0
		|| data->time_to_sleep == 0
		|| data->time_to_eat == 0 || data->meals_count == 0)
	{
		write(2, "Invalid Arguments\n", 19);
		return (0);
	}
	return (1);
}

void	ft_usleep(long long desire_time)
{
	usleep(desire_time * 98 / 100);
}

int	main(int ac, char **av)
{
	t_args		data;

	if (check_args(ac, av))
	{		
		if (data_init(&data, ac, av) == 0)
			return (0);
		init_philos(data);
	}
}
