/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouate <ytouate@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 11:42:23 by ytouate           #+#    #+#             */
/*   Updated: 2022/03/28 12:23:10 by ytouate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdlib.h>
# include <sys/time.h>
# include <string.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_list{
	int				val;
	struct s_list	*next;
}t_list;

typedef struct philos_data_s{
	int	num_of_philos;
	int	num_of_forks;
	int	time_to_eat;
	int	time_to_die;
	int	time_to_sleep;
	int	meals_count;
}t_philos_data;

#endif