# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gachalif <gachalif@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/13 12:46:16 by gachalif          #+#    #+#              #
#    Updated: 2024/02/29 11:06:12 by gachalif         ###   ########.fr        #
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

UP		= "\033[1F"
CLR		= "\033[2K"
YELLOW	= "\033[33;1m"
CYAN	= "\033[36;1m"
GREEN	= "\033[32;1m"
DEFAULT	= "\033[0;0m"

define HEADER
███╗   ███╗██╗███╗   ██╗██╗████████╗ █████╗ ██╗     ██╗  ██╗
████╗ ████║██║████╗  ██║██║╚══██╔══╝██╔══██╗██║     ██║ ██╔╝
██╔████╔██║██║██╔██╗ ██║██║   ██║   ███████║██║     █████╔╝ 
██║╚██╔╝██║██║██║╚██╗██║██║   ██║   ██╔══██║██║     ██╔═██╗ 
██║ ╚═╝ ██║██║██║ ╚████║██║   ██║   ██║  ██║███████╗██║  ██╗
╚═╝     ╚═╝╚═╝╚═╝  ╚═══╝╚═╝   ╚═╝   ╚═╝  ╚═╝╚══════╝╚═╝  ╚═╝
\033[36;1mFeb. 2024				  gachalif @42Quebec\033[32;1m
\033[0;1m
Start SERVER 
	./server

Send message with CLIENT 
	./client <SERVER_PID> <MESSAGE>\033[0;0m
endef
export HEADER

all:		$(NAME_SERV) $(NAME_CLIENT)
			@	echo $(GREEN)
			@	echo "$$HEADER"
			@	echo $(DEFAULT)

%.o:	%.c
		@ echo $(UP)$(CLR)🔥 $(YELLOW)$@ 
		@ $(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<

$(NAME_SERV): 	$(LIBFT) $(PRINTF) $(OBJS_SERV)
				@ echo $(UP)$(CLR)🔥 $@ 
				@$(CC) $(CFLAGS) -o $(NAME_SERV) $(SRCS_SERV) $(LIBFT) $(PRINTF)
				@echo $(UP)$(CLR)🖥 $(GREEN) Compiled SERVER 🖥$(DEFAULT)
				@echo	
$(NAME_CLIENT):	$(LIBFT) $(OBJS_CLIENT)
				@ echo $(UP)$(CLR)🔥 $@ 
				@$(CC) $(CFLAGS) -o $(NAME_CLIENT) $(SRCS_CLIENT) $(LIBFT)
				@echo $(UP)$(CLR)👤$(GREEN) Compiled CLIENT 👤$(DEFAULT)

$(LIBFT):	
				@echo 📖 $(YELLOW)Compiling LIBFT 📖 $(DEFAULT)
				@$(LIBFT_MAKE)
				@$(LIBFT_CLEAN)
				@echo $(UP)$(CLR)📖  $(GREEN)Compiled LIBFT 📖 $(DEFAULT)
$(PRINTF):	
				@echo 📖  $(YELLOW)Compiling PRINTF 📖 $(DEFAULT)
				@$(PRINTF_MAKE)
				@$(PRINTF_CLEAN)
				@echo $(UP)$(CLR)📖  $(GREEN)Compiled PRINTF 📖 $(DEFAULT)
				@echo	

clean:
				@rm -f $(OBJS_CLIENT) $(OBJS_SERV)
				@echo 🧽 $(GREEN)All clean!$(DEFAULT)
				@$(LIBFT_CLEAN)
				@$(PRINTF_CLEAN)

fclean: 	
				@rm -f $(OBJS_CLIENT) $(OBJS_SERV)
				@rm -f $(NAME_SERV) $(NAME_CLIENT) 
				@echo 🧽 $(GREEN)All f...clean!$(DEFAULT)
				@$(LIBFT_FCLEAN)
				@$(PRINTF_FCLEAN)
				
re:		
		@	rm -f  $(OBJS_CLIENT) $(OBJS_SERV) $(NAME_SERV) $(NAME_CLIENT) 
		@	$(LIBFT_FCLEAN)
		@	$(PRINTF_FCLEAN)
		@	make all

.PHONY = all clean fclean re