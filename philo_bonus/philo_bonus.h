/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouate <ytouate@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 02:46:54 by ytouate           #+#    #+#             */
/*   Updated: 2022/04/15 23:17:12 by ytouate          ###   ########.fr       */
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
# include <sys/types.h>
# include <signal.h>

# define FORK 1
# define EATING 2
# define THINKING 3
# define SLEEPING 4
# define DIED 5
# define END 6

typedef struct args_s{
	int				num_of_philos;
	int				num_of_forks;
	long long		time_to_die;
	int				time_to_sleep;
	int				time_to_eat;
	int				meals_count;
	long long		start_time;
	sem_t			*print_sema;
	sem_t			*forks;
}t_args;

typedef struct s_data{
	int			id;
	pid_t		pid;
	t_args		args;
	long long	start_time;
	long long	last_meal_time;
	int meals_track;
}t_data;

long long	current_timestamp(void);
int	ft_atoi(const char *str);
int	is_int(char *s);
int	check_args(int ac, char **av);
long long	current_timestamp(void);
void	ft_usleep(long long desired_time);
void	reset(void);
void	green(void);
void	red(void);
void print_message(t_data *data, int act);
int	data_init(t_args *data, int ac, char **av);
t_data* init_needed_data(t_args args, t_data **philos, int i);
#endif