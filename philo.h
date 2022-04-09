/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouate <ytouate@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 11:42:23 by ytouate           #+#    #+#             */
/*   Updated: 2022/04/09 14:49:40 by ytouate          ###   ########.fr       */
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

# define FORK 1
# define EATING 2
# define THINKING 3
# define SLEEPING 4
# define DIED 5

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

typedef struct data
{
	struct timeval		current_time;
	pthread_mutex_t		*fork;
	pthread_mutex_t		*next_fork;
	int					j;
	t_args				args;
}t_data;

int			data_init(t_args *data, int ac, char **av);
int			ft_atoi(const char *str);
int			is_int(char *s);
int			check_args(int ac, char **av);
int			join_philos(pthread_t	*philos, t_args data);
t_data		**put_fork(t_args arg);
t_data		**put_next_fork(t_data **data, t_args args);
t_data		**init_philos(t_args	arg);
t_data		*init_needed_data(t_data **data, t_args args, int i);
long long	current_timestamp(void);
void		reset(void);
void		green(void);
void		print_message(t_data *philo, int act);
void		*ft_philosophers(void *a);
#endif