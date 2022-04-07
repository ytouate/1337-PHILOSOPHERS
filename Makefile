# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ytouate <ytouate@student.1337.ma>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/28 11:44:44 by ytouate           #+#    #+#              #
#    Updated: 2022/04/07 21:59:33 by ytouate          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

all:
	gcc -Wall -Wextra -Werror -fsanitize=address -g philo.c philo_utils.c valid_args.c init_functions.c -o philo

clean:
	rm -rf philo .vscode
