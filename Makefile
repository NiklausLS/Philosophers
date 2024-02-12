# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nileempo <nileempo@42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/09 22:52:15 by nileempo          #+#    #+#              #
#    Updated: 2024/02/12 00:21:56 by nileempo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = main.c \
		./initialisation/init_structure.c \
		./parsing/check_errors.c \
		./parsing/get_args.c \

# compilation rules
CC = gcc
CFLAGS = -Wall -Werror -Wextra
INC_PATH = ./includes
NAME = philo

OBJS = $(SRCS:.c=.o)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INC_PATH)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

all: $(NAME)

clean:
	rm -f $(NAME)
	rm -f $(OBJS)

fclean: clean

re: fclean all

.PHONY: all clean fclean re