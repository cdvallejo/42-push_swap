/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvallejo <cvallejo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 11:33:19 by cvallejo          #+#    #+#             */
/*   Updated: 2023/04/24 10:11:32 by cvallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//Mueve todos los elementos de a 1 posición ascendente
//El primer elemento pasa a ser el último
//1 2 3 -> 2 3 1
void	rotate_a(t_stack *stack_a, int print)
{
	int i;
	int	aux;

	if (stack_a->index == NULL || stack_a->new_size == 1)
		return ;
	aux = stack_a->index[0];
	i = 0;
	while (i < stack_a->new_size -1)
	{
		stack_a->index[i] = stack_a->index[i + 1];
		i++;
	}
	stack_a->index[stack_a->new_size -1] = aux;
	if (print == 1)
		ft_printf("ra\n");
}

//Mueve todos los elementos de b 1 posición ascendente
//El primer elemento pasa a ser el último
void	rotate_b(t_stack *stack_b, int print)
{
	int i;
	int	aux;

	if (stack_b->index == NULL || stack_b->new_size == 1)
		return ;
	aux = stack_b->index[0];
	i = 0;
	while (i < stack_b->new_size -1)
	{
		stack_b->index[i] = stack_b->index[i + 1];
		i++;
	}
	stack_b->index[stack_b->new_size -1] = aux;
	if (print == 1)
		ft_printf("rb\n");
}

//ra y rb al mismo tiempo
//El primer elemento pasa a ser el último en cada stack
void	rr(t_stack *stack_a, t_stack *stack_b)
{
	rotate_a(stack_a, 0);
	rotate_b(stack_b, 0);
	ft_printf("rr\n");
}
