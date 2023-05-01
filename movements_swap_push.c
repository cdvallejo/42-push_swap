/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_swap_push.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvallejo <cvallejo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 11:33:19 by cvallejo          #+#    #+#             */
/*   Updated: 2023/05/01 10:57:03 by cvallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
void	ss(t_stack *stack_a, t_stack *stack_b)
{
	swap_a(stack_a, 0);
	swap_b(stack_b, 0);
	ft_printf("ss\n");
}

//Toma el primer elemento de b y lo pasa al comienzo de A
void	push_a(t_stack *stack_a, t_stack *stack_b)
{
	int	aux;
	int	i;

	if (stack_b->index == NULL)
		return ;
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
	i = 0;
	while (i < stack_b->new_size -1)
	{
		stack_b->index[i] = stack_b->index[i + 1];
		i++;
	}
	stack_b->new_size -= 1;
	ft_printf("pa\n");
}

//Toma el primer elemento de A y lo pasa al comienzo de B
void	push_b(t_stack *stack_a, t_stack *stack_b)
{
	int	aux;
	int	i;

	if (stack_a->index == NULL)
		return ;
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
	while (i < stack_a->new_size -1)
	{
		stack_a->index[i] = stack_a->index[i + 1];
		i++;
	}
	stack_a->new_size -= 1;
	ft_printf("pb\n");
}
