# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/15 11:58:00 by umeneses          #+#    #+#              #
#    Updated: 2024/04/25 18:56:53 by umeneses         ###   ########.fr        #
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

SRC_STUDY				= ./
BUILD_D					= ./build/
LIBS_D					= ../libs/
LIBFT_D					= $(LIBS_D)libft/
HEADERS_ADDED			= $(LIBFT_D)includes/
HEADERS					= ./headers/ $(HEADERS_ADDED)

# **************************************************************************** #
#								FILES										   #
# **************************************************************************** #

LIBFT					= $(addprefix $(LIBFT_D), libft.a)
LIBS					= $(LIBFT_D)libft.a

NAME					= studies

STUDY_FILES				= study_bitwise_02.c

STUDY_FILES_ALL			= $(addprefix $(SRC_STUDY), $(STUDY_FILES))

OBJS_STUDIES			= $(addprefix $(BUILD_D), $(STUDY_FILES_ALL:%.c=%.o))
OBJS_ALL				= $(OBJS_STUDIES)

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
COMP_EXE_STUDY	= $(CC) $(LDFLAGS) $(OBJS_STUDIES) $(LDLIBS) -o $(NAME)

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

all: 				$(NAME) $(NAME_CLIENT)

$(BUILD_D)%.o:		%.c
					@$(MKDIR) $(dir $@)
					@$(COMP_OBJS)
					@echo "Compiling: $(notdir $<)"

$(NAME):		libft_lib $(OBJS_STUDIES)
					@$(COMP_EXE_STUDY)
					@printf "$(GREEN)"
					@echo "SERVER Ready!"
					@printf "$(YELLOW)"
					@echo "Next target >>>> client..."
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
					$(RM) $(NAME)
					@printf "$(RESET)"

re:					fclean all

.PHONY:				all clean fclean re