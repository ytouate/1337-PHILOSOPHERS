/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouate <ytouate@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 11:42:23 by ytouate           #+#    #+#             */
/*   Updated: 2022/04/03 20:53:48 by ytouate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdlib.h>
# include <sys/time.h>
# include <string.h>
# include <time.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>

typedef	struct fork_s{
	int				index;
	pthread_mutex_t	id;
	int				flag;
}t_fork;

typedef struct args_s{
	int	num_of_philos;
	int	num_of_forks;
	int	time_to_die;
	int	time_to_sleep;
	int	time_to_eat;
	int	meals_count;
}t_args;

typedef struct status_s{
	int	is_eating;
	int	is_thinking;
	int	is_sleeping;
	int	is_hungry;
}t_status;

typedef struct philo_s{
	int			index;
	t_status	stats;
	int			left_fork;
	int			right_fork;
	pthread_t	id;
}t_philo;

typedef struct signle_philo
{
	t_philo	p;
	int		j;
	t_fork	f;
	t_args	d;
}t_single_philo;

int				ft_atoi(const char *str);
int				is_int(char *s);
void			check_args(int ac, char **av);
void			data_init(t_args *data, int ac, char **av);
t_fork			*init_forks(t_args	arg);
t_single_philo	*init_philos(t_args	arg, t_fork *f);
t_single_philo	init_needed_data(t_fork *f, t_args args,
					t_single_philo	*philo, int i);
void	join_philos(t_single_philo	*philos, t_args data);
#endif