# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cvallejo <cvallejo@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/26 09:58:38 by cvallejo          #+#    #+#              #
#    Updated: 2023/05/11 16:27:37 by cvallejo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = src/push_swap.c \
src/check_args_1.c \
src/check_args_2.c \
src/utils.c \
src/set_params.c \
src/stack_creation_1.c \
src/stack_creation_2.c \
src/sort_stack.c \
src/sort_3_op.c \
src/sort_4_op_1.c \
src/sort_4_op_2.c \
src/movements_swap.c \
src/movements_push.c \
src/movements_rotate.c \
src/movements_reverse.c \

SRC_BONUS = bonus/checker_bonus.c \
bonus/push_swap_bonus.c \
bonus/check_args_1_bonus.c \
bonus/check_args_2_bonus.c \
bonus/utils_bonus.c \
bonus/set_params_bonus.c \
bonus/stack_creation_1_bonus.c \
bonus/stack_creation_2_bonus.c \
bonus/movements_swap_bonus.c \
bonus/movements_push_bonus.c \
bonus/movements_rotate_bonus.c \
bonus/movements_reverse_bonus.c \
bonus/get_next_line/get_next_line_utils_bonus.c \
bonus/get_next_line/get_next_line_bonus.c

NAME = push_swap
NAME_BONUS = checker
OBJS = ${SRC:.c=.o}
OBJS_BONUS = $(SRC_BONUS:.c=.o)

#COMPILATION UTILS#
LIBRARY = libft/libft.a
BONUS = bonus/checker_bonus.c
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
INCLUDE = -I ./push_swap.h
INCLUDE_BONUS = -I checker_bonus.h

#RULES#
.c.o:
	${CC} ${CFLAGS} -c $< -o $@

all: norminette libft push_swap

norminette:
	@echo "\n *** CHECKING 42 NORMINETTE ***\n"
	@norminette src/
	@norminette bonus/

norminette_bonus:
	@echo "\n *** CHECKING 42 NORMINETTE ***\n"
	@norminette bonus/

libft:
	@echo "\n *** COMPILING LIBFT ***\n"
	@${MAKE} -C ./libft/

compile: ${NAME}

$(NAME): ${OBJS}
	@echo "\n *** COMPILING PUSH_SWAP PROGRAM ***\n"
	@${CC} ${CFLAGS} ${INCLUDE} ${OBJS} ${LIBRARY} -o ${NAME} -L libft -lft

#BONUS RULES#
bonus:	norminette_bonus libft checker

compile_bonus: ${NAME_BONUS}

$(NAME_BONUS):	${OBJS_BONUS}
	@echo "\n *** COMPILING CHECKER PROGRAM ***\n"
	@${CC} ${CFLAGS} ${INCLUDE_BONUS} ${OBJS_BONUS} ${LIBRARY} -o ${NAME_BONUS} -L libft -lft

#CLEAN RULES#
clean:
	@${MAKE} -C ./libft clean
	@${RM} ${OBJS} $(OBJS_BONUS)

fclean: clean
	@${MAKE} -C ./libft fclean
	@${RM} ${NAME} ${NAME_BONUS}

re: fclean all

.PHONY: all clean fclean re libft compile norminette bonus