# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/15 11:58:00 by umeneses          #+#    #+#              #
#    Updated: 2024/04/15 15:01:14 by umeneses         ###   ########.fr        #
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

HEADERS				= ./headers/
HEADERS				+= $(LIBFT_D)includes/
SRC_D				= ./src/
LIBS_D				= ./libs/
LIBFT_D				= $(LIBS_D)libft/
BUILD_D				= ./build/

# **************************************************************************** #
#								FILES										   #
# **************************************************************************** #

LIBFT				= $(addprefix $(LIBFT_D), libft.a)
LIBS				= $(LIBFT)

NAME				= minitalk

FILES				= main.c

FILES_ALL			= $(addprefix $(SRC_D), $(FILES))

OBJS				= $(addprefix $(BUILD_D), $(FILES_ALL:%.c=%.o))
OBJS_ALL			= $(OBJS)

# **************************************************************************** #
#								COMMANDS										   #
# **************************************************************************** #

RM					= rm -rf
MKDIR				= mkdir -p
MV_OBJS				= find . -type f \( -name '.o' -o -name '.a'\) -exec mv {} \

# **************************************************************************** #
#								COMPILATION									   #
# **************************************************************************** #

AUTHOR				= umeneses
CC					= cc
CFLAGS				= -Wall -Wextra -Werror -g3
CPPFLAGS			= $(addprefix -I, $(HEADERS)) -MMD -MP
LDFLAGS				= -ldl -pthread -lm
COMPILE_OBJS		= $(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@
COMPILE_EXE			= $(CC) $(OBJS_ALL) $(LDFLAGS) $(LIBS) -o $(NAME)

# **************************************************************************** #
#								TARGETS										   #
# **************************************************************************** #

all: 				libft_lib $(NAME)

$(BUILD_D)%.o:		%.c
					$(MKDIR) $(dir $@)
					$(COMPILE_OBJS)
					@echo "Compiling: $(notdir $<)"

$(NAME):			$(OBJS_ALL)
					$(COMPILE_EXE)
					@printf "$(GREEN)"
					@echo "Minitalk Ready!"
					@printf "$(YELLOW)"
					@echo "Now, hit on terminal: './server' and './client PID MESSAGE'"
					@printf "$(RESET)"

libft_lib:
					@printf "$(CYAN)"
					$(MAKE) -C $(LIBFT_D)
					@printf "$(RESET)"

clean:
					$(RM) $(OBJS_ALL)
					$(RM) $(BUILD_D)
					$(MAKE) -C $(LIBFT_D) fclean

fclean:				clean
					$(RM) $(NAME)

re:					fclean all

.PHONY:				all clean fclean re