# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/26 20:31:36 by umeneses          #+#    #+#              #
#    Updated: 2024/01/19 11:35:27 by umeneses         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 				= libft.a

AUTHOR				= umeneses

SRC_FTS				= ft_atoi.c
SRC_FTS				+= ft_bzero.c
SRC_FTS				+= ft_calloc.c
SRC_FTS				+= ft_isalnum.c
SRC_FTS				+= ft_isalpha.c
SRC_FTS				+= ft_isascii.c
SRC_FTS				+= ft_isdigit.c
SRC_FTS				+= ft_isprint.c
SRC_FTS				+= ft_memchr.c
SRC_FTS				+= ft_memcmp.c
SRC_FTS				+= ft_memcpy.c
SRC_FTS				+= ft_memmove.c
SRC_FTS				+= ft_memset.c
SRC_FTS				+= ft_strchr.c
SRC_FTS				+= ft_strdup.c
SRC_FTS				+= ft_strlcat.c
SRC_FTS				+= ft_strlcpy.c
SRC_FTS				+= ft_strlen.c
SRC_FTS				+= ft_strncmp.c
SRC_FTS				+= ft_strnstr.c
SRC_FTS				+= ft_strrchr.c
SRC_FTS				+= ft_tolower.c
SRC_FTS				+= ft_toupper.c
SRC_FTS				+= ft_substr.c
SRC_FTS				+= ft_itoa.c		
SRC_FTS				+= ft_putchar_fd.c
SRC_FTS				+= ft_putstr_fd.c
SRC_FTS				+= ft_putendl_fd.c
SRC_FTS				+= ft_putnbr_fd.c
SRC_FTS				+= ft_striteri.c
SRC_FTS				+= ft_strmapi.c
SRC_FTS				+= ft_strjoin.c
SRC_FTS				+= ft_split.c	
SRC_FTS				+= ft_strtrim.c
# ****** libft functions ****** #

SRC_FTS				+= ft_lstadd_back_void.c
SRC_FTS				+= ft_lstadd_front_void.c
SRC_FTS				+= ft_lstclear_void.c
SRC_FTS				+= ft_lstdelone_void.c
SRC_FTS				+= ft_lstiter_void.c
SRC_FTS				+= ft_lstlast_t_list.c
SRC_FTS				+= ft_lstmap_t_list.c
SRC_FTS				+= ft_lstnew_t_list.c
SRC_FTS				+= ft_lstsize_int.c
# ****** bonus libft functions ****** #

SRC_FTS				+= ft_printf.c
SRC_FTS				+= ft_printf_placeholder.c
SRC_FTS				+= ft_put_unsigned_nbr.c
SRC_FTS				+= ft_putnbrbase.c
SRC_FTS				+= ft_putptr.c
# ****** ft_printf functions ****** #

SRC_FTS				+= ft_get_next_line.c
SRC_FTS				+= ft_gnl_clear_nodes.c
SRC_FTS				+= ft_gnl_get_let.c
SRC_FTS				+= ft_gnl_get_line.c
SRC_FTS				+= ft_gnl_join_let.c
SRC_FTS				+= ft_gnl_join_line.c
# ****** gnl functions ****** #

INCLUDE				= libft.h

OBJS 				= $(SRC_FTS:.c=.o)

AR 					= ar -rcs
RM 					= rm -f
CC 					= cc
CFLAGS 				= -Wall -Wextra -Werror

all:				$(NAME)

$(NAME):			$(OBJS)

%.o: %.c
					$(CC) -c $(CFLAGS) $< -o $@
					$(AR) $(NAME) $@

#gnl_lib:
#				@printf "$(YELLOW)"
#				$(MAKE) -C $(GNL_D)
#				@echo "Checking File..."
#				nm $(GNL)
#				@printf "$(RESET)"

clean:
					$(RM) $(OBJS)

fclean:				clean
					$(RM) $(NAME)

re:					fclean all

.PHONY:				all clean fclean re $(NAME)


