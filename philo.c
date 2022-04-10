/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouate <ytouate@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 11:44:37 by ytouate           #+#    #+#             */
/*   Updated: 2022/04/09 20:38:33 by ytouate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_data		**philos;
	t_args		data;

	philos = NULL;
	if (check_args(ac, av))
	{
		if (data_init(&data, ac, av) == 0)
			return (0);
		philos = init_philos(data);
		
	}
}
