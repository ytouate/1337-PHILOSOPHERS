/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouate <ytouate@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 17:38:12 by ytouate           #+#    #+#             */
/*   Updated: 2022/04/09 14:24:42 by ytouate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
