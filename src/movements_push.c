/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_push.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvallejo <cvallejo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 11:33:19 by cvallejo          #+#    #+#             */
/*   Updated: 2023/05/10 12:23:32 by cvallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

//Toma el primer elemento de b y lo pasa al comienzo de A
void	push_a(t_stack *stack_a, t_stack *stack_b, int print)
{
	int	i;
	int	aux;

	stack_a->new_size += 1;
	if (stack_a->new_size > 1)
	{
		aux = stack_b->index[0];
		i = stack_a->new_size -2;
		while (i >= 0)
		{
			stack_a->index[i + 1] = stack_a->index[i];
			i--;
		}
		stack_a->index[0] = aux;
	}
	else
		stack_a->index[0] = stack_b->index[0];
	placing_pusher_stack(stack_b);
	if (print == 1)
		ft_printf("pa\n");
}

//Toma el primer elemento de A y lo pasa al comienzo de B
void	push_b(t_stack *stack_a, t_stack *stack_b, int print)
{
	int	i;
	int	aux;

	stack_b->new_size += 1;
	if (stack_b->new_size > 1)
	{
		aux = stack_a->index[0];
		i = stack_b->new_size -2;
		while (i >= 0)
		{
			stack_b->index[i + 1] = stack_b->index[i];
			i--;
		}
		stack_b->index[0] = aux;
	}
	else
		stack_b->index[0] = stack_a->index[0];
	i = 0;
	placing_pusher_stack(stack_a);
	if (print == 1)
		ft_printf("pb\n");
}

//Subfunción que recoloca el stack que acaba de hacer push
void	placing_pusher_stack(t_stack *stack_origin)
{
	int	i;

	i = 0;
	while (i < stack_origin->new_size -1)
	{
		stack_origin->index[i] = stack_origin->index[i + 1];
		i++;
	}
	stack_origin->new_size -= 1;
}
