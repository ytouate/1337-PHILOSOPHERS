/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouate <ytouate@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 11:44:37 by ytouate           #+#    #+#             */
/*   Updated: 2022/04/02 11:53:15 by ytouate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	data_init(t_args *data, int ac, char **av)
{
	if (ac != 5 && ac != 6)
		exit(write(2, "Invalid Arguments\n", 19));
	data->num_of_philos = ft_atoi(av[1]);
	data->num_of_forks = data->num_of_philos;
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		data->meals_count = ft_atoi(av[5]);
	else
		data->meals_count = INT_MIN;
}

int	is_int(char *s)
{
	int	i;

	i = -1;
	while (s[++i])
		if (!(s[i] >= '0' && s[i] <= '9'))
			return (0);
	return (1);
}

void	check_args(int ac, char **av)
{
	int	i;

	i = 0;
	if (ac == 5 || ac == 6)
	{
		while (++i < ac)
			if (is_int(av[i]) == 0 || av[i][0] == '\0')
				exit(write(2, "some or all arguments are not integers\n", 40));
	}
	else
		exit(write(1, "The number of arguments is invalid\n", 36));
}

void *routine(void *a)
{
	(void)a;
	// printf("Hello form thread %d\n", *(int *)a);
	// free(a);
	return (0);
}

t_fork	*init_forks(t_args	arg)
{
	t_fork			*forks;
	pthread_mutex_t	*p;
	int				flag;
	int				i;
	
	i = 0;
	p = malloc(sizeof(pthread_mutex_t) * arg.num_of_forks);
	if (!p)
		return (NULL);
	flag = pthread_mutex_init(&p[i], NULL);
	if (flag == -1)
		exit(write(2, "an error occured while initializing a mutex\n", 45));
	forks = add_fork(i + 1, p[i]);
	arg.num_of_forks--;
	while (arg.num_of_forks)
	{
		flag = pthread_mutex_init(&p[++i], NULL);
		if (flag == -1)
			exit(write(2, "an error occured while initializing a mutex\n", 45));
		append_fork(&forks, add_fork(i + 1, p[i]));
		arg.num_of_forks--;
	}
	return (forks);
}

t_philo	*init_philos(t_args	arg)
{
	int		i;
	t_philo	*philos;
	pthread_t	*p;
	int flag;
	
	i = 0;
	p = malloc(sizeof(pthread_t) * arg.num_of_philos);
	if (!p)
		exit(1);
	
	flag = pthread_create(&p[i], NULL, routine, NULL);
	if (flag == -1)
		exit(write(2, "an error occured while creating threads\n", 41));
	philos = malloc(sizeof(t_philo) * arg.num_of_philos);
	philos->id = p[i];
	philos->index = i + 1;
	arg.num_of_philos--;
	while (arg.num_of_philos)
	{
		flag = pthread_create(&p[++i], NULL, routine, NULL);
		if (flag == -1)
			exit(write(2, "an error occured while creating threads\n", 41));
		append_philo(&philos, add_philo(i + 1, p[i]));
		arg.num_of_philos--;
	}
	return (philos);
}

void join_philos(t_philo	*philos)
{
	while (philos)
	{
		pthread_join(philos->id, NULL);
		philos = philos->next;
	}
}

int	main(int ac, char **av)
{
	t_philo			*philos;
	t_fork			*forks;
	t_args			data;
	int				i;

	i = 0;
	check_args(ac, av);
	data_init(&data, ac, av);
	
	forks = init_forks(data);
	philos = init_philos(data);
	join_philos(philos);
	memset(philos, 0, sizeof(pthread_t) * data.num_of_philos);
}
