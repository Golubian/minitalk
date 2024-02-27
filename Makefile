# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gachalif <gachalif@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/13 12:46:16 by gachalif          #+#    #+#              #
#    Updated: 2024/02/27 10:48:28 by gachalif         ###   ########.fr        #
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

PRINTF = ft_printf/libftprintf.a
PRINTF_MAKE = make -C ft_printf -s
PRINTF_CLEAN = make clean -C ft_printf -s
PRINTF_FCLEAN = make fclean -C ft_printf -s


all:		$(NAME_SERV) $(NAME_CLIENT)

$(NAME_SERV): 	$(LIBFT) $(PRINTF) $(OBJS_SERV)
					gcc $(CFLAGS) -o $(NAME_SERV) $(SRCS_SERV) $(LIBFT) $(PRINTF)

$(NAME_CLIENT):	$(LIBFT) $(OBJS_CLIENT)
					gcc $(CFLAGS) -o $(NAME_CLIENT) $(SRCS_CLIENT) $(LIBFT)

$(LIBFT):	
				@echo "compiling libft.a"
				@$(LIBFT_MAKE)
				@$(LIBFT_CLEAN)
				@echo "libft.a compiled"
$(PRINTF):	
				@echo "compiling libftprintf.a"
				@$(PRINTF_MAKE)
				@$(PRINTF_CLEAN)
				@echo "libftprintf.a compiled"

clean:
				rm -f $(OBJS_CLIENT) $(OBJS_SERV)
				@$(LIBFT_CLEAN)
				@$(PRINTF_CLEAN)

fclean: 	clean
				rm -f $(NAME_SERV) $(NAME_CLIENT) 
				@$(LIBFT_FCLEAN)
				@$(PRINTF_FCLEAN)
				
re:			fclean all

.PHONY = all bonus clean fclean re