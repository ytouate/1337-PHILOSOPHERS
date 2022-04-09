# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ytouate <ytouate@student.1337.ma>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/28 11:44:44 by ytouate           #+#    #+#              #
#    Updated: 2022/04/09 14:43:40 by ytouate          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all:
	gcc -Wall -Wextra -Werror -fsanitize=address philo.c philo_utils.c philo_routine.c print_funcs.c valid_args.c init_functions.c -o philo

clean:
	rm -rf philo .vscode
