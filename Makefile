# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ngoulios <ngoulios@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/12 17:11:59 by ngoulios          #+#    #+#              #
#    Updated: 2024/11/12 17:21:44 by ngoulios         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap.a

CC = cc
CFLAGS = -Wall -Wextra -Werror -I./

# **************************************************************************** #
#                                 Source Files                                 #
# **************************************************************************** #


SRC = output/ft_putchar_fd.c


SRCS = $(SRC_CTYPE) $(SRC_MEMORY) $(SRC_STRING) $(SRC_MATH) $(SRC_OUTPUT) $(SRC_LIST) $(SRC_GNL)


OBJS = $(SRCS:.c=.o)


HEADER = libft.h

# **************************************************************************** #
#                                 Makefile Rules                               #
# **************************************************************************** #


all: $(NAME)


$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)


%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@


clean:
	rm -f $(OBJS)


fclean: clean
	rm -f $(NAME)


re: fclean all


.PHONY: all clean fclean re