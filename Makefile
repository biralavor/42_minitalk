# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/15 11:58:00 by umeneses          #+#    #+#              #
#    Updated: 2024/04/29 11:51:41 by umeneses         ###   ########.fr        #
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
BONUS_D					= ./bonus/
SRC_SV_BONUS_D			= $(BONUS_D)server/
SRC_CL_BONUS_D			= $(BONUS_D)client/
BUILD_D					= ./build/
LIBS_D					= ./libs/
LIBFT_D					= $(LIBS_D)libft/
HEADERS_ADDED			= $(LIBFT_D)includes/
HEADERS_ADDED			+= $(BONUS_D)headers/
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
CLIENT_FILES			+= client_signal.c
CLIENT_FILES			+= client_val.c

SERVER_FILES_ALL		= $(addprefix $(SRC_SERVER_D), $(SERVER_FILES))
CLIENT_FILES_ALL		= $(addprefix $(SRC_CLIENT_D), $(CLIENT_FILES))

OBJS_SERVER				= $(addprefix $(BUILD_D), $(SERVER_FILES_ALL:%.c=%.o))
OBJS_CLIENT				= $(addprefix $(BUILD_D), $(CLIENT_FILES_ALL:%.c=%.o))
OBJS_ALL				= $(OBJS_SERVER) $(OBJS_CLIENT)

# **************************** #
#			BONUS			   #
# **************************** #

NAME_SERVER_BONUS		= server_bonus
NAME_CLIENT_BONUS		= client_bonus

SERVER_FILES_BONUS		= server_main_bonus.c

CLIENT_FILES_BONUS		= client_main_bonus.c
CLIENT_FILES_BONUS		+= client_signal_bonus.c
CLIENT_FILES_BONUS		+= client_val_bonus.c

SRC_SV_BONUS_ALL		= $(addprefix $(SRC_SV_BONUS_D), $(SERVER_FILES_BONUS))
SCR_CL_BONUS_ALL		= $(addprefix $(SRC_CL_BONUS_D), $(CLIENT_FILES_BONUS))

OBJS_SV_BONUS			= $(addprefix $(BUILD_D), $(SRC_SV_BONUS_ALL:%.c=%.o))
OBJS_CL_BONUS			= $(addprefix $(BUILD_D), $(SCR_CL_BONUS_ALL:%.c=%.o))
OBJS_ALL_BONUS			= $(OBJS_SV_BONUS) $(OBJS_CL_BONUS)

# **************************************************************************** #
#								COMMANDS									   #
# **************************************************************************** #

RM					= rm -rf
MKDIR				= mkdir -p
MV_OBJS				= find . -type f \( -name '.o' -o -name '.a'\) -exec mv {} \

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
					@echo "#########   THE CONVERSINHA PROJECT   #########"
					@echo "                                               "
					@printf "$(RESET)"
endef

define				minitalk_header_bonus
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
					@echo "################  WITH BONUS  #################"
					@echo "                                               "
					@printf "$(RESET)"
endef

define				instructions
					@echo "Now, open two terminals and hit on each:"
					@echo "Terminal #1: ./server"
					@printf "Terminal #2: ./client "
					@echo "[server's_PID] [your_message]"
endef

define				instructions_bonus
					@echo "Now, open two terminals and hit on each:"
					@echo "Terminal #1: ./server_bonus"
					@printf "Terminal #2: ./client_bonus "
					@echo "[server's_PID] [your_message]"
endef

ifdef				WITH_BONUS
	NAME_SERVER		= $(NAME_SERVER_BONUS)
	NAME_CLIENT		= $(NAME_CLIENT_BONUS)
	OBJS_SERVER		= $(OBJS_SV_BONUS)
	OBJS_CLIENT		= $(OBJS_CL_BONUS)
	OBJS_ALL		= $(OBJS_ALL_BONUS)
	minitalk_header	= $(minitalk_header_bonus)
	instructions	= $(instructions_bonus)
endif

define				bonus
					$(MAKE) WITH_BONUS=TRUE --no-print-directory
endef

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
					@echo "Next target >>> client..."
					@printf "$(RESET)"

$(NAME_CLIENT):		libft_lib $(OBJS_CLIENT)
					@$(COMP_EXE_CLIENT)
					@printf "$(GREEN)"
					@echo "CLIENT Ready!"
					$(call minitalk_header)
					@printf "$(YELLOW)"
					$(call instructions)
					@printf "$(RESET)"

libft_lib:
					@printf "$(YELLOW)"
					@echo ">>> Checking LIBFT"
					@printf "$(CYAN)"
					@$(MAKE) -C $(LIBFT_D) --no-print-directory
					@printf "$(YELLOW)"
					@echo "Next target >>> server..."
					@printf "$(RESET)"

bonus:
					$(call bonus)

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
					$(RM) $(NAME_SERVER_BONUS) $(NAME_CLIENT_BONUS)
					@printf "$(RESET)"

re:					fclean all

.PHONY:				all clean fclean re bonus