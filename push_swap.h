/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvallejo <cvallejo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 15:48:25 by cvallejo          #+#    #+#             */
/*   Updated: 2023/05/01 16:50:05 by cvallejo         ###   ########.fr       */
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
}		t_stack;

//push_swap.c functions
char	**check_params(int ac, char **av);
void	check_ac(int ac, char **split_av, int i);

//check_args.c functions
int		is_number(char *str);
void	check_number(int ac, char **split_av, int i);
int		strlen_split(char **split_av);
int		check_repeat_number(int ac, char **av, int i);
void	check_int(int ac, char **split_av, int i);

//set_params.c
int		*set_params(int ac, char **split_av);
int		*set_params_string(int ac, char **split_av, int *numbers);
int		*set_params_no_string(int ac, char **split_av, int *numbers);

//stack_creation.c functions
void	stack_a_creation(t_stack *stack_a, int *numbers, char **split_av);
void	stack_value(t_stack *stack_a, int *numbers);
void	stack_index(t_stack *stack_origin);
void	target_position(t_stack *stack_a, t_stack *stack_b);
int		stack_is_sorted(t_stack *stack_a);
void	stack_positions(t_stack *stack_origin);

//sort_stack.c functions
void	sort_numbers(t_stack *stack_a, t_stack *stack_b);
void	sort_2(t_stack *stack_a);
void	sort_3(t_stack *stack_a);
void	sort_4_or_more(t_stack *stack_a, t_stack *stack_b);

//sort_3_op.c functions
void    sort_3_cases_1_to_3(t_stack *stack_a);
void    sort_3_cases_4_to_6(t_stack *stack_a);

//sort_4_op.c functions
void	stack_b_to_stack_a(t_stack *stack_a, t_stack *stack_b);
int 	cost_calculator(t_stack *stack_a, t_stack *stack_b);
int		check_total_cost(t_stack *stack_b, int cost_a, int cost_b, int i, int *candidate, int total_cost);
int		check_double_movements(t_stack *stack_a, t_stack *stack_b, int candidate);
void	stack_a_moves(t_stack *stack_a, t_stack *stack_b, int candidate);
void	stack_b_moves(t_stack *stack_a, t_stack *stack_b, int candidate);
void	final_sort(t_stack *stack_a, int count, int candidate);

//Sorting functions
void	swap_a(t_stack *stack_a, int print);
void	swap_b(t_stack *stack_b, int print);
void	ss(t_stack *stack_a, t_stack *stack_b);
void	rotate_a(t_stack *stack_a, int print);
void	rotate_b(t_stack *stack_b, int print);
void	rr(t_stack *stack_a, t_stack *stack_b);
void	reverse_rotate_a(t_stack *stack_a, int print);
void	reverse_rotate_b(t_stack *stack_b, int print);
void	rrr(t_stack *stack_a, t_stack *stack_b);
void	push_a(t_stack *stack_a, t_stack *stack_b);
void	push_b(t_stack *stack_a, t_stack *stack_b);

//utils.c functions
void	print_error(void);
void	free_memory(char **function);
void	free_memory_int(int *function);
void	free_stack(t_stack *stack_origin);

//debug.c functions BY JOTA
void	debug_leaks(void);
void	debug_print(char *message, ...);
void	debug_print_stack(t_stack *stack, char *name);
void	debug_print_pos(t_stack *stack, char *name);
void	debug_print_value(t_stack *stack, char *name);

#endif