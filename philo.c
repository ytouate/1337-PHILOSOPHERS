/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouate <ytouate@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 11:44:37 by ytouate           #+#    #+#             */
/*   Updated: 2022/04/03 23:06:14 by ytouate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
