/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvallejo <cvallejo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 12:34:17 by cvallejo          #+#    #+#             */
/*   Updated: 2023/05/01 14:37:42 by cvallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*Ordenamiento con 3 números:
Casos: 1 2 3 | 1 3 2 | 2 1 3 */
void    sort_3_cases_1_to_3(t_stack *stack_a)
{
    if (stack_a->index[0] < stack_a->index[1]
		&& stack_a->index[1] < stack_a->index[2]
		&& stack_a->index[0] < stack_a->index[2])
		return ;
	else if (stack_a->index[0] < stack_a->index[1]
		&& stack_a->index[1] > stack_a->index[2]
		&& stack_a->index[0] < stack_a->index[2])
	{
		reverse_rotate_a(stack_a, 1);
		swap_a(stack_a, 1);
	}
	else if (stack_a->index[0] > stack_a->index[1]
		&& stack_a->index[1] < stack_a->index[2]
		&& stack_a->index[0] < stack_a->index[2])
		swap_a(stack_a, 1); 
}

/*Ordenamiento con 3 números:
Casos: 2 3 1 | 3 1 2 | 3 2 1 */
void    sort_3_cases_4_to_6(t_stack *stack_a)
{
    if (stack_a->index[0] < stack_a->index[1]
		&& stack_a->index[1] > stack_a->index[2]
		&& stack_a->index[0] > stack_a->index[2])
		reverse_rotate_a(stack_a, 1);
	else if (stack_a->index[0] > stack_a->index[1]
		&& stack_a->index[1] < stack_a->index[2]
		&& stack_a->index[0] > stack_a->index[2])
		rotate_a(stack_a, 1);
	else if (stack_a->index[0] > stack_a->index[1]
		&& stack_a->index[1] > stack_a->index[2]
		&& stack_a->index[0] > stack_a->index[1])
	{
		rotate_a(stack_a, 1);
		swap_a(stack_a, 1);
	}
}
