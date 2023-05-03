# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cvallejo <cvallejo@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/26 09:58:38 by cvallejo          #+#    #+#              #
#    Updated: 2023/05/03 17:20:22 by cvallejo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = push_swap.c \
check_args.c \
utils.c \
set_params.c \
stack_creation.c \
sort_stack.c \
sort_3_op.c \
sort_4_op_1.c \
sort_4_op_2.c \
movements_swap_push.c \
movements_rotate.c \
movements_reverse.c \
debug.c

SRC_BONUS = checker_bonus.c \
push_swap_bonus.c \
check_args_bonus.c \
utils_bonus.c \
set_params_bonus.c \
stack_creation_bonus.c \
movements_swap_push_bonus.c \
movements_rotate_bonus.c \
movements_reverse_bonus.c \
get_next_line/get_next_line_utils_bonus.c \
get_next_line/get_next_line_bonus.c \
get_next_line/get_next_line_bonus.h

NAME = push_swap
NAME_BONUS = checker
OBJS = ${SRC:.c=.o}
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

#COMPILATION UTILS#
LIBRARY = libft/libft.a
BONUS = bonus/checker_bonus.c
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
INCLUDE = -I push_swap.h

#RULES#
.c.o:
	${CC} ${CFLAGS} -c $< -o $@

all: libft push_swap

libft:
	@echo "\n *** COMPILING LIBFT ***\n"
	@${MAKE} -C ./libft/

compile: ${NAME}

$(NAME): ${OBJS}
	@echo "\n *** COMPILING PUSH_SWAP PROGRAM ***\n"
	@${CC} ${CFLAGS} ${INCLUDE} ${OBJS} ${LIBRARY} -o ${NAME} -L libft -lft

#BONUS RULES#
bonus:	libft compile_bonus checker

compile_bonus: ${NAME_BONUS}

$(NAME_BONUS):	$(OBJS_BONUS)
	@echo "\n *** COMPILING CHECKER PROGRAM ***\n"
	$(CC) $(CFLAGS) $(INCLUDE) $(OBJS_BONUS) ${LIBRARY} -o $(NAME_BONUS)

#CLEAN RULES#
clean:
	@${MAKE} -C ./libft clean
	@${RM} ${OBJS} $(OBJS_BONUS)

fclean: clean
	@${MAKE} -C ./libft fclean
	@${RM} ${NAME} ${NAME_BONUS}

re: fclean all

.PHONY: all clean fclean re libft compile norminette bonus