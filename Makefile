# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ohladkov <ohladkov@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/11 11:45:36 by ohladkov          #+#    #+#              #
#    Updated: 2025/04/03 00:54:43 by ohladkov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	ft_printf.c ft_print_str.c ft_print_hex.c ft_print_digit.c \
			format.c utils.c

NAME	= libftprintf.a

OBJS	= $(SRCS:.c=.o)

CC		= cc

CFLAGS	= -Wall -Wextra -Werror

HEAD 	= ft_printf.h

all:		$(NAME)

$(NAME):	$(OBJS)
		ar -rcs $(NAME) $(OBJS)

%.o: %.c	$(HEAD)
		$(CC) $(CFLAGS) -c -o $@ $<

bonus: all

clean:
		rm -f *.o

fclean:		clean
		rm -f $(NAME)

re:		fclean all
