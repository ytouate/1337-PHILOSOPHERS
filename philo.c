/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouate <ytouate@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 11:44:37 by ytouate           #+#    #+#             */
/*   Updated: 2022/04/01 13:10:58 by ytouate          ###   ########.fr       */
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

void	*philo_routine(void *a)
{
	(void)a;
	return (0);
}

void thread_join(t_list *philos)
{
	int flag;
	flag = 0;
	while (philos)
	{
		flag = pthread_join(philos->val.id, NULL);
		if (flag == -1)
			exit(write(2, "an error occured while joining threads \n", 41));
		philos = philos->next;
	}
}

t_list	*thread_init(t_args data, pthread_t *p)
{
	t_list	*philos = NULL;
	int		i;
	int		flag;
	int		j;

	i = 0;
	j = 0;
	flag = 0;
	flag = pthread_create(&p[j], NULL, philo_routine, NULL);
	if (flag == -1)
		exit(write(2, "an error occured while creating threads\n", 41));
	philos = lst_new(i + 1, p[j]);
	while (++i < data.num_of_philos)
	{
		flag = pthread_create(&p[++j], NULL, philo_routine, NULL);
		if (flag == -1)
			exit(write(2, "an error occured while creating threads\n", 41));
		lst_add_back(&philos, lst_new(i + 1, p[j]));
	}
	thread_join(philos);
	return (philos);
}

int	main(int ac, char **av)
{
	t_list			*philos;
	pthread_t		*threads;
	t_args			data;

	check_args(ac, av);
	data_init(&data, ac, av);
	threads = malloc(sizeof(pthread_t) * data.num_of_philos);
	if (!threads)
		return (1);
	memset(threads, 0, sizeof(pthread_t) * data.num_of_philos);
	philos = thread_init(data, threads);
	while (philos)
	{
		printf("im philo %d\n", philos->val.index);
		printf("my id is %llu\n", (unsigned long long)philos->val.id);
		printf("my fork  id is %d\n", philos->val.fork_id);
		printf("the meals i have eaten are %d\n", philos->val.eaten_meals);
		philos = philos-> next;
	}
}
