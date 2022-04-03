/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ytouate <ytouate@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 17:38:12 by ytouate           #+#    #+#             */
/*   Updated: 2022/04/03 11:46:38 by ytouate          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_int(char *s)
{
	int	i;

	i = -1;
	while (s[++i])
		if (!(s[i] >= '0' && s[i] <= '9'))
        {
            if (s[i] == '-')
                exit(write(2, "args cannot be negative\n", 25));
			return (0);
        }
            
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
