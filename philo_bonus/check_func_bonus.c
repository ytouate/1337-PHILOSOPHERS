/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_func_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouate <ytouate@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 23:01:37 by ytouate           #+#    #+#             */
/*   Updated: 2022/04/15 23:17:38 by ytouate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

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

int	is_int(char *s)
{
	int	i;

	i = -1;
	while (s[++i])
	{
		if (!(s[i] >= '0' && s[i] <= '9'))
		{
			if (s[i] == '-')
				return (-1);
			return (0);
		}
	}
	return (1);
}

int	check_args(int ac, char **av)
{
	int	i;

	i = 0;
	if (ac == 5 || ac == 6)
	{
		while (++i < ac)
		{
			if (is_int(av[i]) == 0 || av[i][0] == '\0')
			{
				write(2, "some or all arguments are not integers\n", 40);
				return (0);
			}
			else if (is_int(av[i]) == -1)
			{
				write(2, "args cannot be negative\n", 25);
				return (0);
			}
		}
	}
	else
	{
		exit(write(1, "The number of arguments is invalid\n", 36));
		return (0);
	}
	return (1);
}
