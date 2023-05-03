/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_4_op_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvallejo <cvallejo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 17:51:55 by cvallejo          #+#    #+#             */
/*   Updated: 2023/05/02 16:27:21 by cvallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Subfunción para ahorrar movimientos haciendo rr las veces
que coincidan ambos stacks. Los movimientos restantes serán individuales */
void	do_rr(t_stack *stack_a, t_stack *stack_b)
{
	while (stack_a->cost_a > 0 && stack_b->cost_b > 0)
	{
		rr(stack_a, stack_b);
		stack_a->cost_a--;
		stack_b->cost_b--;
	}
	while (stack_a->cost_a > 0)
	{
		rotate_a(stack_a, 1);
		stack_a->cost_a--;
	}
	while (stack_b->cost_b > 0)
	{
		rotate_b(stack_b, 1);
		stack_b->cost_b--;
	}
}

/* Mueve A haciendo ra / rra las veces necesarias según la posición
del candidato en B*/
void	stack_a_moves(t_stack *stack_a, t_stack *stack_b, int candidate)
{
	int	i;

	i = stack_b->target_pos[candidate];
	if (i <= (stack_a->new_size / 2 + 1))
	{
		while (i > 0)
		{
			rotate_a(stack_a, 1);
			i--;
		}
	}
	else
	{
		while (i < stack_a->new_size)
		{
			reverse_rotate_a(stack_a, 1);
			i++;
		}
	}
}

/* Mueve B haciendo ra / rra las veces necesarias según la posición
de su candidato*/
void	stack_b_moves(t_stack *stack_a, t_stack *stack_b, int candidate)
{
	int	i;

	i = stack_b->pos[candidate];
	if (i <= (stack_b->new_size / 2 + 1))
	{
		while (i > 0)
		{
			rotate_b(stack_b, 1);
			i--;
		}
	}
	else
	{
		while (i < stack_b->new_size)
		{
			reverse_rotate_b(stack_b, 1);
			i++;
		}
	}
}

/* Ordenación final de A en el caso de que el index 1 no haya quedado
arriba del stack. Para ello buscamos la posición más pequeña y la guardamos
hasta encontrar al index 1. Desde esa posición, con final_movemnents
haremos los ra / rra necesarios para llevarlo a la primera posición*/
void	final_sort(t_stack *stack_a)
{
	int	i;
	int	min;
	int	pos;

	i = 0;
	min = stack_a->size;
	while (i < stack_a->size)
	{
		if (stack_a->index[i] < min)
		{
			min = stack_a->index[i];
			pos = i;
		}
		i++;
	}
	final_movements(stack_a, pos);
}

/* Subfunción de final_sort que realiza los ra / rra
necesarios para el index de valor 1 a la primera posición */
void	final_movements(t_stack *stack_a, int pos)
{
	if (pos <= (stack_a->size / 2 + 1))
	{
		while (pos > 0)
		{
			rotate_a(stack_a, 1);
			pos--;
		}
	}
	else
	{
		while (pos < stack_a->size)
		{
			reverse_rotate_a(stack_a, 1);
			pos++;
		}
	}
}
