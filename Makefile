# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cvallejo <cvallejo@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/26 09:58:38 by cvallejo          #+#    #+#              #
#    Updated: 2023/05/01 12:40:21 by cvallejo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = push_swap.c \
check_args.c \
utils.c \
set_params.c \
stack_creation.c \
sort_stack.c \
sort_3_op.c \
sort_4_op.c \
movements_swap_push.c \
movements_rotate.c \
movements_reverse.c \
debug.c

OBJS = ${SRC:.c=.o}
NAME = push_swap

#BONUS#


#COMPILATION UTILS#
LIBRARY = libft/libft.a
CC = gcc -g
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
INCLUDE = -I push_swap.h

#RULES#
.c.o:
	${CC} ${FLAGS} -c $< -o $@

all: libft push_swap

libft:
	@echo "\n *** COMPILING LIBFT ***\n"
	@${MAKE} -C ./libft/

compile: ${NAME}

$(NAME): ${OBJS}
	@echo "\n *** COMPILING PUSH_SWAP PROGRAM ***\n"
	@${CC} ${INCLUDE} ${OBJS} ${LIBRARY} -o ${NAME}

#BONUS RULES#


#CLEAN RULES#

clean:
	@${MAKE} -C ./libft clean
	@${RM} ${OBJS}

fclean: clean
	@${MAKE} -C ./libft fclean
	@${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re libft compile norminette