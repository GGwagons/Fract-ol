# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: miturk <miturk@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/15 11:26:09 by miturk            #+#    #+#              #
#    Updated: 2023/12/19 17:45:24 by miturk           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	Fract-ol
CC			=	cc
FLAGS		=	-g -Wall -Werror -Wextra
EXTRA		=	-lmlx -lXext -lX11 -lm
RM			=	rm -f
SRC			=	Fract_ol.c\
				Julia.c\
				mandelbrot.c\
				
OBJS		=	$(SRC:.c=.o)

%.o:%.c
		$(CC) $(FLAGS) -c $< -o $@ 

INCLUDE		= minilibx-linux/libmlx.a\
			  minilibx-linux/libmlx_Linux.a\
			  libft/*.a \
			  ft_printf/*.a\

all: 		$(NAME)

$(NAME): 	library $(OBJS) 
			$(CC) $(FLAGS) $(EXTRA) -o $(NAME) $(OBJS) $(INCLUDE) 

library:
			@ make -C libft/
			@ make -C ft_printf/
			@ make -C minilibx-linux/

clean:		
			@ $(RM) $(OBJS)
			@ make -C libft/ clean
			@ make -C ft_printf/ clean
			@ make -C minilibx-linux/ clean

fclean: 	clean
			@ $(RM) $(NAME) 
			@ make -C libft/ fclean
			@ make -C ft_printf/ fclean

re: 		fclean all

.PHONY: all clean fclean re libft ft_printf/ minilibx-linux/ Fract-ol