# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: miturk <miturk@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/19 10:29:03 by miturk            #+#    #+#              #
#    Updated: 2023/12/04 10:50:33 by miturk           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= ft_printf.a
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
AR			= ar rcs
RM			= rm -f
SRC_FILES	=   ft_printf \
				ft_putchar_p \
				ft_putdi \
				ft_puthex \
				ft_putptr \
				ft_puts \
				ft_putu 

SRCS_DIR	=	./
SRCS		=	$(addprefix $(SRCS_DIR), $(addsuffix .c, $(SRC_FILES)))

OBJS_DIR	=	./
OBJS		=	$(addprefix $(OBJS_DIR), $(addsuffix .o, $(SRC_FILES)))

all: $(NAME)

$(OBJS_DIR)%.o: $(SRCS_DIR)%c
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJS)
		@$(AR) $(NAME) $(OBJS)

clean:
		$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: clean all

.PHONY: all clean fclean re

