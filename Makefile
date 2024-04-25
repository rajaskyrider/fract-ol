# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rpandipe <rpandipe.student.42luxembourg    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/24 17:24:12 by rpandipe          #+#    #+#              #
#    Updated: 2024/04/25 18:29:58 by rpandipe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= fractol
LIBFT		= libft.a
CC			= cc
CFLAG		= -Wall -Werror -Wextra -g
RM 			= rm -rf
SRCS		= test.c
OBJS		= $(SRCS:.c=.o)

all : $(NAME)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -I/usr/include -Imlx_linux -O3 -c $< -o $@

$(NAME): $(OBJS)
	@make -C libft
	@cp libft/$(LIBFT) .
	$(CC) $(OBJS) $(LIBFT) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

clean:
	cd libft && $(MAKE) clean
	$(RM) $(OBJS)

fclean:	clean
	cd libft && $(MAKE) fclean
	$(RM) $(NAME) $(LIBFT)

re: fclean all

.PHONY: all clean fclean re
