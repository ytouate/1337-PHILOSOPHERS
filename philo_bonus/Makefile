# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ytouate <ytouate@student.1337.ma>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/13 01:43:01 by ytouate           #+#    #+#              #
#    Updated: 2022/04/13 21:17:44 by ytouate          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo_bonus
CC = gcc
# CFLAGS = -Wall -Wextra -Werror

FILES = \
		./philo_bonus.c

O_FILES = $(FILES:.c=.o)

$(NAME): $(O_FILES)
	@ar -rc philo_bonus.a $(O_FILES)
	@$(CC) $(CFLAGS) philo_bonus.a -o $(NAME)

all: $(NAME)

clean:
	@rm -f $(O_FILES)

fclean: clean
	@rm -rf philo_bonus philo_bonus.a .vscode 

re: fclean all