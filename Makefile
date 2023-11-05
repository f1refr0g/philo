# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abeaudet <abeaudetfr0g42@gmail.com>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/13 17:45:13 by abeaudet          #+#    #+#              #
#    Updated: 2023/11/05 10:52:16 by abeaudet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo


#sources files
S = srcs/
SRCS_FILES = philo.c\
			parsing.c\
			utils.c\
			utils2.c\
			utils3.c\
			action.c\
			death.c\


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
	@leaks --atExit -- ./philo 200 60 60 60 4
	
valgrind: all
	valgrind --leak-check=full --show-leak-kinds=all ./philo 5 800 200 200 10

run: all
	./philo 10 60 60 60

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
