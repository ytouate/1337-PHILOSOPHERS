/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouate <ytouate@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 11:44:37 by ytouate           #+#    #+#             */
/*   Updated: 2022/04/03 11:56:14 by ytouate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *a)
{
	t_single_philo	*temp;

	temp = a;
	return (temp);
}

void	join_philos(t_single_philo	*philos, t_args data)
{
	int	i;

	i = -1;
	while (++i < data.num_of_forks)
		if (pthread_join(philos[i].p.id, NULL) == -1)
			exit(write(2, "an error occured while joining the threads\n", 44));
}

int	main(int ac, char **av)
{
	t_single_philo	*philos;
	t_fork			*forks;
	t_args			data;

	philos = NULL;
	check_args(ac, av);
	data_init(&data, ac, av);
	forks = init_forks(data);
	philos = init_philos(data, forks);
	join_philos(philos, data);
}
