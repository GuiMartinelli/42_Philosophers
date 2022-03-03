# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: guferrei <guferrei@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/16 09:48:26 by guferrei          #+#    #+#              #
#    Updated: 2022/03/03 09:49:44 by guferrei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PATH_SRC = src

NAME = philo_bonus
MAIN = $(PATH_SRC)/philo_bonus.c
SRC = $(PATH_SRC)/utils/args.c $(PATH_SRC)/utils/time_utils.c $(PATH_SRC)/forks/forks.c $(PATH_SRC)/routine/routine.c $(PATH_SRC)/utils/args_utils.c
CC = gcc
CFLAGS = -Wall -Wextra -Werror -pthread

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) $(MAIN) $(SRC) -o $(NAME)

clean:
	rm $(NAME)

fclean: clean

norma:
	norminette

re: clean all