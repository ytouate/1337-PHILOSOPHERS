/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouate <ytouate@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 11:44:37 by ytouate           #+#    #+#             */
/*   Updated: 2022/04/07 21:42:23 by ytouate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_data	**philos;
	t_args			data;

	philos = NULL;
	check_args(ac, av);
	data_init(&data, ac, av);
	philos = init_philos(data);
}
