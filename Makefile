# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abeaudet <abeaudetfr0g42@gmail.com>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/13 17:45:13 by abeaudet          #+#    #+#              #
#    Updated: 2023/08/21 09:20:15 by abeaudet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo


#sources files
S = srcs/
SRCS_FILES = philo.c\
			parsing.c\
			utils.c\


SRCS = $(addprefix $S, $(SRCS_FILES))

OBJS = $(SRCS:%.c=%.o)

O = /objs
$O%.o: $S%
	
CC = gcc
CFLAGS = -Wall -Werror -Wextra
all: $(NAME)

$(NAME):	$(OBJS)
	@$(CC) -o $@ $(CFLAGS) $(OBJS)


COMMIT = $(shell date "+%d %B %T")
git:
	@git add .
	@git commit -m "$(COMMIT)"
	@git push

leaks:
	@leaks --atExit -- ./philo
	
valgrind: all
	valgrind --leak-check=full --show-leak-kinds=all ./philo

clean:
	@rm -f $(OBJS)
	@echo "$B Cleaning complete.$W"

fclean: clean
	@rm -f $(NAME)

re: fclean all

# COLORS
R = $(shell tput -Txterm setaf 1)
G = $(shell tput -Txterm setaf 2)
C = $(shell tput -Txterm setaf 6)
W = $(shell tput -Txterm setaf 7)
