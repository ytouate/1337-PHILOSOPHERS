/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouate <ytouate@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 02:46:54 by ytouate           #+#    #+#             */
/*   Updated: 2022/04/13 14:44:27 by ytouate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
#define PHILO_BONUS_H

# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <semaphore.h>
# include <sys/time.h>

typedef struct args_s{
	int				num_of_philos;
	int				num_of_forks;
	long long		time_to_die;
	int				time_to_sleep;
	int				time_to_eat;
	int				meals_count;
	long long		start_time;
	pthread_mutex_t	*print_lock;
}t_args;

#endif