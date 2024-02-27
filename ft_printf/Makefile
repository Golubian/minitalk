# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gachalif <gachalif@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/13 12:46:16 by gachalif          #+#    #+#              #
#    Updated: 2024/02/15 15:50:57 by gachalif         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra $(INCLUDES)

INCLUDES = -I includes \

SRCS_DIR = srcs

SRCS = 	$(SRCS_DIR)/ft_printf.c \
		$(SRCS_DIR)/ft_putchar.c \
		$(SRCS_DIR)/ft_putstr.c \
		$(SRCS_DIR)/ft_putint.c \
		$(SRCS_DIR)/ft_putuint.c \
		$(SRCS_DIR)/ft_puthex.c \
		$(SRCS_DIR)/ft_putptr.c \
		

OBJS = $(SRCS:.c=.o)

$(NAME): 	$(OBJS)
				ar rcs $(NAME) $(OBJS)

all:		$(NAME)

clean:
				rm -f $(OBJS) $(OBJS_BONUS)

fclean: 	clean
				rm -f $(NAME) $(OBJS_BONUS)

re:			fclean $(NAME)

.PHONY = all bonus clean fclean re