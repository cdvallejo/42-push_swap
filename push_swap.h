/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvallejo <cvallejo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 15:48:25 by cvallejo          #+#    #+#             */
/*   Updated: 2023/05/11 16:24:31 by cvallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"

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

//push_swap.c functions
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

//set_params.c functions
int		*set_params(int ac, char **split_av);
int		*set_params_string(char **split_av, int *numbers);
int		*set_params_no_string(int ac, char **split_av, int *numbers);

//stack_creation_1.c functions
void	stack_a_creation(t_stack *stack_a, int *numbers, char **split_av);
void	stack_b_creation(t_stack *stack_a, t_stack *stack_b);
void	stack_value(t_stack *stack_a, int *numbers);
void	stack_index(t_stack *stack_origin);

//stack_creation_2.c functions
void	stack_pos_and_target(t_stack *stack_A, t_stack *stack_b);
void	target_position(t_stack *stack_a, t_stack *stack_b);
void	stack_positions(t_stack *stack_origin);
void	free_target_pos(t_stack	*stack_b);

//sort_stack.c functions
void	sort_numbers(t_stack *stack_a, t_stack *stack_b);
void	sort_2(t_stack *stack_a);
void	sort_3(t_stack *stack_a);
void	sort_4_or_more(t_stack *stack_a, t_stack *stack_b);

//sort_3_op.c functions
void	sort_3_cases_1_to_3(t_stack *stack_a);
void	sort_3_cases_4_to_6(t_stack *stack_a);

//sort_4_op_1.c functions
void	stack_b_to_stack_a(t_stack *stack_a, t_stack *stack_b);
int		cost_calculator(t_stack *stack_a, t_stack *stack_b);
int		cost_calculator_calculates(t_stack *stack_a, t_stack *stack_b,
			int *candidate);
int		check_double_movements(t_stack *stack_a, t_stack *stack_b,
			int candidate);
void	do_rrr(t_stack *stack_a, t_stack *stack_b);

//sort_4_op_2.c functions
void	do_rr(t_stack *stack_a, t_stack *stack_b);
void	stack_a_moves(t_stack *stack_a, t_stack *stack_b, int candidate);
void	stack_b_moves(t_stack *stack_b, int candidate);
void	final_sort(t_stack *stack_a);
void	final_movements(t_stack *stack_a, int pos);

//movements_swap.c functions
void	swap_a(t_stack *stack_a, int print);
void	swap_b(t_stack *stack_b, int print);
void	ss(t_stack *stack_a, t_stack *stack_b, int print);

//movements_push.c functions
void	push_a(t_stack *stack_a, t_stack *stack_b, int print);
void	push_b(t_stack *stack_a, t_stack *stack_b, int print);
void	placing_pusher_stack(t_stack *stack_origin);

//movements_rotate.c functions
void	rotate_a(t_stack *stack_a, int print);
void	rotate_b(t_stack *stack_b, int print);
void	rr(t_stack *stack_a, t_stack *stack_b, int print);

//movements_reverse.c functions
void	reverse_rotate_a(t_stack *stack_a, int print);
void	reverse_rotate_b(t_stack *stack_b, int print);
void	rrr(t_stack *stack_a, t_stack *stack_b, int print);

//utils.c functions
int		stack_is_sorted(t_stack *stack_a);
void	print_error(void);
void	free_memory(char **function);
void	free_memory_int(int *function);
void	free_stack(t_stack *stack_origin);

//debug.c functions
void	debug_leaks(void);
void	debug_print(char *message, ...);
void	debug_print_stack(t_stack *stack, char *name);
void	debug_print_pos(t_stack *stack, char *name);
void	debug_print_value(t_stack *stack, char *name);

#endif