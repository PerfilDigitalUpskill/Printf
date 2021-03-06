# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: malmeida <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/12 14:45:50 by malmeida          #+#    #+#              #
#    Updated: 2021/04/21 15:00:36 by malmeida         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a
SRCS	= $(wildcard ./srcs/*.c)
OBJS	= $(SRCS:.c=.o)
HDRS	= includes
CFLAGS	= -Wall -Wextra -Werror

all:		$(NAME)

$(NAME):	$(OBJS)
			ar rcs $(NAME) $(OBJS)

%.o: %.c
			gcc $(CFLAGS) -I $(HDRS) -c $< -o $@

bonus:		$(NAME)

clean:
			/bin/rm -f $(OBJS)

fclean:		clean
			/bin/rm -f $(NAME)

re:	fclean all
