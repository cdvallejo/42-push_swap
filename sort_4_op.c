/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_4_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvallejo <cvallejo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 17:51:55 by cvallejo          #+#    #+#             */
/*   Updated: 2023/04/27 15:21:30 by cvallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*Función principal para pasar B a A.
Si target_pos es 0, hacemos push_a*/
void	stack_b_to_stack_a(t_stack *stack_a, t_stack *stack_b)
{
	int	i;
	int	count;
	int	candidate;
	int	cost_a;
	int	cost_b;
	int	total_cost;

	count = stack_b->new_size;
	while (count > 0)
	{
		i = 0;
		ft_printf("A Index:\n");
		while (i < stack_a->new_size)
		{
			ft_printf("%d-", stack_a->index[i]);
			i++;
		}
		ft_printf("\n");
		ft_printf("CHECK stack_b:\n");
		i = 0;
		ft_printf("B Index:\n");
		while (i < stack_b->new_size)
		{
			ft_printf("%d-", stack_b->index[i]);
			i++;
		}
		ft_printf("\n");
		ft_printf("-POSICIONES ACTUALES DE A:\n");
		stack_positions(stack_a);
		ft_printf("-POSICIONES ACTUALES DE B:\n");
		stack_positions(stack_b);
		ft_printf("\n");
		if (stack_b->target_pos[0] == 0)
		{
			push_a(stack_a, stack_b);
			target_position(stack_a, stack_b);
		}
		else
		{
			candidate = cost_calculator(stack_a, stack_b, candidate, cost_a,
					cost_b);
			ft_printf("EL CANDIDATO ES: %d\n", candidate);
			stack_a_moves(stack_a, stack_b, candidate);
			stack_b_moves(stack_a, stack_b, candidate);
			target_position(stack_a, stack_b);
		}
		count--;
	}
	if (stack_is_sorted(stack_a) == 1)
		return ;
	else
		final_sort(stack_a, i, count, candidate);
	//RESULTADO FINAL:
	ft_printf("*********************\n");
	ft_printf("El resultado FINAL ES:\n");
	ft_printf("*********************\n");
	i = 0;
	while (i < stack_a->new_size)
	{
		ft_printf("A Index: %d\n", stack_a->index[i]);
		i++;
	}
	ft_printf("----Size: %d - \n", stack_a->new_size);
	ft_printf("CHECK stack_b:\n");
	i = 0;
	while (i < stack_b->new_size)
	{
		ft_printf("Index: %d\n", stack_b->index[i]);
		i++;
	}
	ft_printf("----Size: %d - \n", stack_b->new_size);
	ft_printf("-POSICIONES ACTUALES DE A:\n");
	stack_positions(stack_a);
	ft_printf("-POSICIONES ACTUALES DE B:\n");
	stack_positions(stack_b);
}

/*Calculamos los costes de mover cada número (posición) en B (y en A según el número de B).
Si el cálculo de ambos stacks es negativo,
	significa que lo mejor es hacer rrr; si es positivo 
en ambos,
	rr. En tal caso salimos de la funcióm y recalculamos target_pos. De no ser así,
	
la combinación que sea más pequeña la tomará total_cost y el candidate cogerá esa posición*/
int	cost_calculator(t_stack *stack_a, t_stack *stack_b, int candidate,
		int cost_a, int cost_b)
{
	int	i;
	int	total_cost;

	i = 0;
	cost_b = 0;
	cost_a = 0;
	total_cost = stack_a->size;
	//candidate = 0;
	ft_printf("Calculando el menor coste................\n");
	while (i < stack_b->new_size)
	{
		if (stack_b->pos[i] <= (stack_b->new_size / 2 + 1))
			cost_b = stack_b->pos[i];
		else
			cost_b = (stack_b->pos[i] - stack_b->new_size) * -1;
		if (stack_a->pos[stack_b->target_pos[i]] <= (stack_a->new_size / 2 + 1))
			cost_a = stack_b->target_pos[i];
		else
			cost_a = (stack_a->pos[stack_b->target_pos[i]] - stack_a->new_size)
				* -1;
		/*if (cost_a < 0 && cost_b < 0)
		{
			candidate = -500;
			rrr(stack_a, stack_b);
			target_position(stack_a, stack_b);
			return (candidate);
		}
		if (cost_a > 0 && cost_b > 0)
		{
			candidate = -500;
			rr(stack_a, stack_b);
			target_position(stack_a, stack_b);
			return (candidate);
		}*/
		if (total_cost > cost_a + cost_b)
		{
			total_cost = cost_a + cost_b;
			candidate = stack_b->pos[i];
		}
		i++;
	}
	ft_printf("El menor coste es: %d\n", total_cost);
	return (candidate);
}

void	stack_a_moves(t_stack *stack_a, t_stack *stack_b, int candidate)
{
	int	i;

	i = stack_b->target_pos[candidate];
	ft_printf("este es el target_pos: %d\n", i);
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
		push_a(stack_a, stack_b);
	}
	else
	{
		while (i < stack_b->new_size)
		{
			reverse_rotate_b(stack_b, 1);
			i++;
		}
		push_a(stack_a, stack_b);
	}
}

void	final_sort(t_stack *stack_a, int i, int count, int candidate)
{
	ft_printf("FINAAAAAAAAAL SORT\n");
	i = 0;
	count = stack_a->size;
	ft_printf("cont=%d\n", count);
	while (i < stack_a->size)
	{
		if (stack_a->index[i] < count)
		{
			count = stack_a->index[i];
			candidate = stack_a->pos[i];
		}
		i++;
		ft_printf("cont=%d\n", count);
	}
	if (candidate <= (stack_a->size / 2 + 1))
	{
		while (candidate > 0)
		{
			rotate_a(stack_a, 1);
			candidate--;
		}
	}
	else
	{
		while (candidate < stack_a->size)
		{
			reverse_rotate_a(stack_a, 1);
			candidate++;
		}
	}
}
