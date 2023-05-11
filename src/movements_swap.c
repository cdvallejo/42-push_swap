/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvallejo <cvallejo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 11:33:19 by cvallejo          #+#    #+#             */
/*   Updated: 2023/05/10 12:05:20 by cvallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//Intercambia los dos primeros números de A
void	swap_a(t_stack *stack_a, int print)
{
	int	aux;

	if (stack_a->index == NULL || stack_a->new_size == 1)
		return ;
	aux = stack_a->index[0];
	stack_a->index[0] = stack_a->index[1];
	stack_a->index[1] = aux;
	if (print == 1)
		ft_printf("sa\n");
}

//Intercambia los dos primeros números de B
void	swap_b(t_stack *stack_b, int print)
{
	int	aux;

	if (stack_b->index == NULL || stack_b->new_size == 1)
		return ;
	aux = stack_b->index[0];
	stack_b->index[0] = stack_b->index[1];
	stack_b->index[1] = aux;
	if (print == 1)
		ft_printf("sb\n");
}

//sa y sb al mismo tiempo
void	ss(t_stack *stack_a, t_stack *stack_b, int print)
{
	swap_a(stack_a, 0);
	swap_b(stack_b, 0);
	if (print == 1)
		ft_printf("ss\n");
}
