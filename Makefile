# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/15 11:58:00 by umeneses          #+#    #+#              #
#    Updated: 2024/04/26 21:05:00 by umeneses         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#								COLORS										   #
# **************************************************************************** #

RED				:= \033[0;31m
GREEN			:= \033[0;32m
YELLOW			:= \033[0;33m
BLUE			:= \033[0;34m
PURPLE			:= \033[0;35m
CYAN			:= \033[0;36m
RESET			:= \033[0m

# **************************************************************************** #
#								PATHS										   #
# **************************************************************************** #

SRC_SERVER_D			= ./src/server/
SRC_CLIENT_D			= ./src/client/
BUILD_D					= ./build/
LIBS_D					= ./libs/
LIBFT_D					= $(LIBS_D)libft/
HEADERS_ADDED			= $(LIBFT_D)includes/
HEADERS					= ./headers/ $(HEADERS_ADDED)

# **************************************************************************** #
#								FILES										   #
# **************************************************************************** #

LIBFT					= $(addprefix $(LIBFT_D), libft.a)
LIBS					= $(LIBFT_D)libft.a

NAME_SERVER				= server
NAME_CLIENT				= client

SERVER_FILES			= server_main.c

CLIENT_FILES			= client_main.c
#CLIENT_FILES			+= client_signal.c
CLIENT_FILES			+= client_val.c

SERVER_FILES_ALL		= $(addprefix $(SRC_SERVER_D), $(SERVER_FILES))
CLIENT_FILES_ALL		= $(addprefix $(SRC_CLIENT_D), $(CLIENT_FILES))

OBJS_SERVER				= $(addprefix $(BUILD_D), $(SERVER_FILES_ALL:%.c=%.o))
OBJS_CLIENT				= $(addprefix $(BUILD_D), $(CLIENT_FILES_ALL:%.c=%.o))
OBJS_ALL				= $(OBJS_SERVER) $(OBJS_CLIENT)

# **************************************************************************** #
#								COMMANDS									   #
# **************************************************************************** #

RM					= rm -rf
MKDIR				= mkdir -p
MV_OBJS				= find . -type f \( -name '.o' -o -name '.a'\) -exec mv {} \

# **************************************************************************** #
#								COMPILATION									   #
# **************************************************************************** #

AUTHOR			= umeneses
CC				= cc
CFLAGS			= -Wall -Wextra -Werror -g3
CPPFLAGS		= $(addprefix -I, $(HEADERS)) -MMD -MP
LDFLAGS			= $(addprefix -L, $(dir $(LIBS)))
LDLIBS			= -lft -ldl
COMP_OBJS		= $(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@
COMP_EXE_SERVER	= $(CC) $(LDFLAGS) $(OBJS_SERVER) $(LDLIBS) -o $(NAME_SERVER)
COMP_EXE_CLIENT	= $(CC) $(LDFLAGS) $(OBJS_CLIENT) $(LDLIBS) -o $(NAME_CLIENT)

# **************************************************************************** #
#								DEFINES										   #
# **************************************************************************** #

define				minitalk_header
					@printf "$(CYAN)"
					@echo "                                               "
					@echo "###############   WELCOME TO   ################"
					@echo "                        _ _        _           "
					@echo "               (_)     (_) |      | | |        "
					@echo "      _ __ ___  _ _ __  _| |_ __ _| | | __     "
					@echo "     |  _   _ \| |  _ \| | __/ _  | | |/ /     "
					@echo "     | | | | | | | | | | | || (_) | |   <      "
					@echo "     |_| |_| |_|_|_| |_|_|\__\__,_|_|_|\_\     "
					@echo "                                               "
					@echo "###############################################"
					@echo "                                               "
					@printf "$(RESET)"
endef

# **************************************************************************** #
#								TARGETS										   #
# **************************************************************************** #

all: 				$(NAME_SERVER) $(NAME_CLIENT)

$(BUILD_D)%.o:		%.c
					@$(MKDIR) $(dir $@)
					@$(COMP_OBJS)
					@echo "Compiling: $(notdir $<)"

$(NAME_SERVER):		libft_lib $(OBJS_SERVER)
					@$(COMP_EXE_SERVER)
					@printf "$(GREEN)"
					@echo "SERVER Ready!"
					@printf "$(YELLOW)"
					@echo "Next target >>>> client..."
					@printf "$(RESET)"

$(NAME_CLIENT):		libft_lib $(OBJS_CLIENT)
					@$(COMP_EXE_CLIENT)
					@printf "$(GREEN)"
					@echo "CLIENT Ready!"
					$(call minitalk_header)
					@printf "$(YELLOW)"
					@echo "Now, open two terminals and hit on each:"
					@echo "Terminal #1: ./server"
					@echo "Terminal #2: ./client [server's_PID] [your_message]"
					@printf "$(RESET)"


libft_lib:
					@printf "$(YELLOW)"
					@echo ">>> Checking LIBFT"
					@printf "$(CYAN)"
					@$(MAKE) -C $(LIBFT_D)
					@printf "$(YELLOW)"
					@echo "Next target >>>> server..."
					@printf "$(RESET)"

clean:
					@printf "$(RED)"
					@echo ">>> Cleaning objects"
					@printf "$(PURPLE)"
					$(RM) $(OBJS_ALL)
					$(RM) $(BUILD_D)
					$(MAKE) -C $(LIBFT_D) fclean
					@printf "$(RESET)"

fclean:				clean
					@printf "$(RED)"
					@echo ">>> Cleaning executables"
					@printf "$(PURPLE)"
					$(RM) $(NAME_SERVER) $(NAME_CLIENT)
					@printf "$(RESET)"

re:					fclean all

.PHONY:				all clean fclean re