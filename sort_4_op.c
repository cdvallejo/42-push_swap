/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_4_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvallejo <cvallejo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 17:51:55 by cvallejo          #+#    #+#             */
/*   Updated: 2023/05/01 17:06:27 by cvallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	do_rrr(t_stack *stack_a, t_stack *stack_b, int cost_a, int cost_b);
static void	do_rr(t_stack *stack_a, t_stack *stack_b, int cost_a, int cost_b);

/*Función principal para pasar B a A.
Si target_pos es 0, hacemos push_a*/
void	stack_b_to_stack_a(t_stack *stack_a, t_stack *stack_b)
{
	int	count;
	int	candidate;

	count = stack_b->new_size;
	while (count > 0)
	{
		stack_positions(stack_a);
		stack_positions(stack_b);
		target_position(stack_a, stack_b);
		if (stack_b->target_pos[0] == 0)
			push_a(stack_a, stack_b);
		else
		{
			candidate = cost_calculator(stack_a, stack_b);
			if (check_double_movements(stack_a, stack_b, candidate) == 0)
			{
				stack_a_moves(stack_a, stack_b, candidate);
				stack_b_moves(stack_a, stack_b, candidate);
			}
			push_a(stack_a, stack_b);
		}
		debug_print_stack(stack_a, "a-value: ");
		debug_print_stack(stack_b, "b-value: ");
		count--;
	}
	if (stack_is_sorted(stack_a) == 1)
		return ;
	final_sort(stack_a, count, candidate);
}

/*Calculamos los costes de mover cada número (posición) en B (y en A según
	el número de B).
En tal caso salimos de la función y recalculamos target_pos. De no ser así,
	la combinación que sea más pequeña la tomará total_cost y el candidate
	cogerá esa posición*/
int	cost_calculator(t_stack *stack_a, t_stack *stack_b)
{
	int	i;
	int	total_cost;
	int	cost_a;
	int	cost_b;
	int	candidate;

	i = 0;
	cost_b = 0;
	cost_a = 0;
	total_cost = stack_a->size;
	while (i < stack_b->new_size)
	{
		if (i <= (stack_b->new_size / 2 + 1))
			cost_b = i;
		else
			cost_b = (stack_b->new_size - i);
		if (stack_a->pos[stack_b->target_pos[i]] <= (stack_a->new_size / 2 + 1))
			cost_a = stack_b->target_pos[i];
		else
			cost_a = (stack_a->new_size - stack_a->pos[stack_b->target_pos[i]]);
		debug_print("coste_a: %i - coste_b: %i\n", cost_a, cost_b);
		total_cost = check_total_cost(stack_b, cost_a, cost_b, i, &candidate, total_cost);
		i++;
	}
	debug_print("total_cost: %d\n", total_cost);
	return (candidate);
}

int	check_total_cost(t_stack *stack_b, int cost_a, int cost_b, int i,
		int *candidate, int total_cost)
{
	if (total_cost > cost_a + cost_b)
	{
		total_cost = cost_a + cost_b;
		*candidate = stack_b->pos[i];
	}
	return (total_cost);
}

/*Si el cálculo de ambos stacks es negativo, significa que lo mejor es hacer
	rrr; si es positivo en ambos, rr.*/
int	check_double_movements(t_stack *stack_a, t_stack *stack_b, int candidate)
{
	int	cost_a;
	int	cost_b;

	cost_b = 0;
	cost_a = 0;
	if (candidate <= (stack_b->new_size / 2 + 1))
		cost_b = candidate;
	else
		cost_b = (candidate - stack_b->new_size);
	if (stack_a->pos[stack_b->target_pos[candidate]] <= (stack_a->new_size / 2
			+ 1))
		cost_a = stack_b->target_pos[candidate];
	else
		cost_a = (stack_a->pos[stack_b->target_pos[candidate]]
				- stack_a->new_size);
	if (cost_a < 0 && cost_b < 0)
	{
		do_rrr(stack_a, stack_b, cost_a, cost_b);
		return (1);
	}
	else if (cost_a > 0 && cost_b > 0)
	{
		do_rr(stack_a, stack_b, cost_a, cost_b);
		return (1);
	}
	return (0);
}

static void	do_rrr(t_stack *stack_a, t_stack *stack_b, int cost_a, int cost_b)
{
	while (cost_a < 0 && cost_b < 0)
	{
		rrr(stack_a, stack_b);
		cost_a++;
		cost_b++;
	}
	while (cost_a < 0)
	{
		reverse_rotate_a(stack_a, 1);
		cost_a++;
	}
	while (cost_b < 0)
	{
		reverse_rotate_b(stack_b, 1);
		cost_b++;
	}
}

static void	do_rr(t_stack *stack_a, t_stack *stack_b, int cost_a, int cost_b)
{
	while (cost_a > 0 && cost_b > 0)
	{
		rr(stack_a, stack_b);
		cost_a--;
		cost_b--;
	}
	while (cost_a > 0)
	{
		rotate_a(stack_a, 1);
		cost_a--;
	}
	while (cost_b > 0)
	{
		rotate_b(stack_b, 1);
		cost_b--;
	}
}

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

void	final_sort(t_stack *stack_a, int count, int candidate)
{
	int	i;

	i = 0;
	count = stack_a->size;
	while (i < stack_a->size)
	{
		if (stack_a->index[i] < count)
		{
			count = stack_a->index[i];
			candidate = stack_a->pos[i];
		}
		i++;
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
	if (stack_a->index[stack_a->size - 1] < stack_a->index[0])
		reverse_rotate_a(stack_a, 1);
}

