/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvallejo <cvallejo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 15:48:25 by cvallejo          #+#    #+#             */
/*   Updated: 2023/05/11 16:24:49 by cvallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H
# include "libft/libft.h"
# include "bonus/get_next_line/get_next_line_bonus.h"
# include <stdbool.h>

typedef struct stack
{
	int	*value;
	int	*index;
	int	*pos;
	int	*target_pos;
	int	size;
	int	new_size;
	int	cost_a;
	int	cost_b;
}		t_stack;

//push_swap_bonus.c functions
char	**check_params(int ac, char **av);
void	check_ac(int ac, char **split_av, int i);

//check_args_1.c functions
int		is_number(char *str);
void	check_number(int ac, char **split_av, int i);
int		strlen_split(char **split_av);

//check_args_2.c functions
int		check_repeat_number(int ac, char **av, int i);
void	check_int(char **split_av, int i);
int		check_zeros_maxlen(char *str);

//set_params_bonus.c functions
int		*set_params(int ac, char **split_av);
int		*set_params_string(char **split_av, int *numbers);
int		*set_params_no_string(int ac, char **split_av, int *numbers);

//stack_creation_bonus.c functions
void	stack_a_creation(t_stack *stack_a, int *numbers, char **split_av);
void	stack_b_creation(t_stack *stack_a, t_stack *stack_b);
void	stack_value(t_stack *stack_a, int *numbers);
void	stack_index(t_stack *stack_origin);

//stack_creation_2_bonus.c functions
void	target_position(t_stack *stack_a, t_stack *stack_b);
void	stack_positions(t_stack *stack_origin);
void	free_target_pos(t_stack	*stack_b);

//movements_swap_bonus.c functions
void	swap_a(t_stack *stack_a, int print);
void	swap_b(t_stack *stack_b, int print);
void	ss(t_stack *stack_a, t_stack *stack_b, int print);

//movements_push_bonus.c functions
void	push_a(t_stack *stack_a, t_stack *stack_b, int print);
void	push_b(t_stack *stack_a, t_stack *stack_b, int print);
void	placing_pusher_stack(t_stack *stack_origin);

//movements_rotate_bonus.c functions
void	rotate_a(t_stack *stack_a, int print);
void	rotate_b(t_stack *stack_b, int print);
void	rr(t_stack *stack_a, t_stack *stack_b, int print);

//movements_reverse_bonus.c functions
void	reverse_rotate_a(t_stack *stack_a, int print);
void	reverse_rotate_b(t_stack *stack_b, int print);
void	rrr(t_stack *stack_a, t_stack *stack_b, int print);

//utils_bonus.c functions
int		stack_is_sorted(t_stack *stack_a);
void	print_error(void);
void	free_memory(char **function);
void	free_memory_int(int *function);
void	free_stack(t_stack *stack_origin);

#endif