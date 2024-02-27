# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gachalif <gachalif@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/13 12:46:16 by gachalif          #+#    #+#              #
#    Updated: 2024/02/27 08:44:38 by gachalif         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_SERV = server
NAME_CLIENT = client

CC = gcc
CFLAGS = -Wall -Werror -Wextra $(INCLUDES)

INCLUDES = -I includes \

SRCS_DIR_SERV = srcs_server
SRCS_DIR_CLIENT = srcs_client

SRCS_SERV = 	$(SRCS_DIR_SERV)/server.c \

SRCS_CLIENT =	$(SRCS_DIR_CLIENT)/client.c \

OBJS_SERV = $(SRCS_SERV:.c=.o)
OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)

LIBFT = libft/libft.a
LIBFT_MAKE = make -C libft -s
LIBFT_CLEAN = make clean -C libft -s
LIBFT_FCLEAN = make fclean -C libft -s

all:		$(NAME_SERV) $(NAME_CLIENT)

$(NAME_SERV): 	$(LIBFT) $(OBJS_SERV)
					gcc $(CFLAGS) -o $(NAME_SERV) $(SRCS_SERV) $(LIBFT)

$(NAME_CLIENT):	$(LIBFT) $(OBJS_CLIENT)
					gcc $(CFLAGS) -o $(NAME_CLIENT) $(SRCS_CLIENT) $(LIBFT)

$(LIBFT):	
				@echo "compiling libft.a"
				@$(LIBFT_MAKE)
				@$(LIBFT_CLEAN)
				@echo "libft.a compiled"

clean:
				rm -f $(OBJS_CLIENT) $(OBJS_SERV)
				@$(LIBFT_CLEAN)

fclean: 	clean
				rm -f $(NAME_SERV) $(NAME_CLIENT) 
				@$(LIBFT_FCLEAN)
				
re:			fclean all

.PHONY = all bonus clean fclean re