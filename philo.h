/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouate <ytouate@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 11:42:23 by ytouate           #+#    #+#             */
/*   Updated: 2022/04/08 17:15:34 by ytouate          ###   ########.fr       */
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

typedef struct data
{
	t_status		status;
	struct timeval			current_time;
	struct timeval			end_time;
	pthread_mutex_t			print_mutex;
	pthread_mutex_t	*fork;
	pthread_mutex_t	*next_fork;
	int				temp;
	int				j;
	t_args			args;
}t_data;

int				ft_atoi(const char *str);
int				is_int(char *s);
void			check_args(int ac, char **av);
void			data_init(t_args *data, int ac, char **av);
t_data	**init_philos( t_args	arg);
t_data	*init_needed_data(t_data **data, t_args args, int i);
void	join_philos(pthread_t	*philos, t_args data);
#endif