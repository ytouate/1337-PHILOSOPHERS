/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouate <ytouate@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 11:42:23 by ytouate           #+#    #+#             */
/*   Updated: 2022/04/02 10:18:40 by ytouate          ###   ########.fr       */
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

typedef	struct fork_s{
	int index;
	pthread_mutex_t	id;
	struct fork_s 	*next;
}t_fork;

typedef struct args_s{
	int	num_of_philos;
	int	num_of_forks;
	int	time_to_die;
	int	time_to_sleep;
	int	time_to_eat;
	int	meals_count;
}t_args;

typedef struct philo_s{
	int			index;
	pthread_t	id;
	struct philo_s	*next;	
}t_philo;

int		ft_atoi(const char *str);
t_fork	*add_fork(int index, pthread_mutex_t id);
void	append_fork(t_fork **origin, t_fork *new);
t_philo	*add_philo(int index, pthread_t id);
void	append_philo(t_philo **origin, t_philo *new);
#endif