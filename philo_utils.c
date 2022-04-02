/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouate <ytouate@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 17:53:08 by ytouate           #+#    #+#             */
/*   Updated: 2022/04/02 10:18:36 by ytouate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *str)
{
	int				i;
	int				sign;
	unsigned long	result;

	i = 0;
	sign = 1;
	result = 0;
	while ((str[i] == ' ') || (str[i] == '\t') || (str[i] == '\r')
		|| (str[i] == '\n') || (str[i] == '\v') || (str[i] == '\f'))
		i++;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			sign = -1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (result > 9223372036854775807)
		{
			if (sign == -1)
				return (0);
			return (-1);
		}
		result = (10 * result) + str[i++] - '0';
	}
	return ((((int)result) * sign));
}

t_fork	*add_fork(int index, pthread_mutex_t id)
{
	t_fork	*new;

	new = malloc(sizeof(t_fork));
	if (!new)
		return (NULL);
	new->index = index;
	new->id = id;
	return (new);
}

void	append_fork(t_fork **origin, t_fork *new)
{
	t_fork	*p;

	p = *origin;
	while (p->next)
		p = p->next;
	p->next = new;
	new->next = NULL;
}

t_philo	*add_philo(int index, pthread_t id)
{
	t_philo	*new;

	new = malloc(sizeof(t_philo));
	if (!new)
		return (NULL);
	new->index = index;
	new->id = id;
	return (new);
}

void	append_philo(t_philo **origin, t_philo *new)
{
	t_philo	*p;

	p = *origin;
	while (p->next)
		p = p->next;
	p->next = new;
	new->next = NULL;
}

