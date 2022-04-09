# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ytouate <ytouate@student.1337.ma>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/28 11:44:44 by ytouate           #+#    #+#              #
#    Updated: 2022/04/09 15:20:23 by ytouate          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC = gcc
CFLAGS = -Wall -Wextra -Werror

FILES = \
		./philo.c			\
		./philo_routine.c	\
		./philo_utils.c		\
		./print_funcs.c		\
		./valid_args.c		\
		./init_functions.c

O_FILES = $(FILES:.c=.o)

all: $(O_FILES)
	ar -rc philo.a $(O_FILES)
	$(CC) $(CFLAGS) philo.a -o $(NAME)

clean:
	rm -f $(O_FILES)

fclean: clean
	rm -f philo philo.a .vscode 
