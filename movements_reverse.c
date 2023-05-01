/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_reverse.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvallejo <cvallejo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 12:01:34 by cvallejo          #+#    #+#             */
/*   Updated: 2023/05/01 10:57:06 by cvallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//Mueve todos los elementos de a 1 posición descendente
//El último elemento pasa a ser el primero
//1 2 3 -> 3 1 2
void	reverse_rotate_a(t_stack *stack_a, int print)
{
	int	i;
	int	aux;

	if (stack_a->index == NULL || stack_a->new_size == 1)
		return ;
	aux = stack_a->index[stack_a->new_size -1];
	i = stack_a->new_size -1;
	while (i >= 0)
	{
		stack_a->index[i + 1] = stack_a->index[i];
		i--;
	}
	stack_a->index[0] = aux;
	if (print == 1)
		ft_printf("rra\n");
}

//Mueve todos los elementos de b 1 posición descendente
//El último elemento pasa a ser el primero
void	reverse_rotate_b(t_stack *stack_b, int print)
{
	int	i;
	int	aux;

	if (stack_b->index == NULL || stack_b->new_size == 1)
		return ;
	aux = stack_b->index[stack_b->new_size -1];
	i = stack_b->new_size -2;
	while (i >= 0)
	{
		stack_b->index[i + 1] = stack_b->index[i];
		i--;
	}
	stack_b->index[0] = aux;
	if (print == 1)
		ft_printf("rrb\n");
}

//Mueve todos los elementos de a y b 1 posición descendente
//El último elemento pasa a ser el primero
void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	reverse_rotate_a(stack_a, 0);
	reverse_rotate_b(stack_b, 0);
	ft_printf("rrr\n");
}
