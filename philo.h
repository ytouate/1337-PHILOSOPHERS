/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouate <ytouate@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 11:42:23 by ytouate           #+#    #+#             */
/*   Updated: 2022/03/29 09:42:59 by ytouate          ###   ########.fr       */
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

typedef struct philos_data_s{
	int	num_of_philos;
	int	num_of_forks;
	int	time_to_eat;
	int	time_to_die;
	int	time_to_sleep;
	int	meals_count;
}t_philos_data;

typedef struct s_list{
	t_philos_data		data;
	pthread_t			id;
	int					index;
	struct s_list		*next;
}t_list;

int	ft_atoi(const char *str);
t_list *lst_new(t_philos_data data, int index, pthread_t id);
void	lst_add_front(t_list **origin, t_list *new);
void    lst_add_back(t_list **origin, t_list *new);
#endif