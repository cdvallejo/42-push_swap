/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_4_op_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvallejo <cvallejo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 17:51:55 by cvallejo          #+#    #+#             */
/*   Updated: 2023/05/03 17:08:30 by cvallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Función principal para pasar B a A. En cada iteración de B, hacemos
un push_a.
1) Establecemos las posiciones de cada stack
2) A cada número de B le calculamos la posición que le corresponde en A
3) Si la posición correspondiente del primer número de B es 0, hacemos push_a.
	Si no, calculamos el número de B con menor coste para mover.
4) Ya con el candidato a mover, comprobamos que si el coste en cada stack
	es ambos positivo o negativo.
5) Si ocurre el paso anterior, ahorramos costes haciendo rr / rrr, los
	movimientos sobrantes serán ra /rb o rra / rrb. Finalmente, push_a.
6) Si no hay movimientos dobles para ahorrar, hacemos los movimientos
	pertinentes en A y en B para hacer, finalmente, push_a.
7) Cuando se han pasado todos los números de B, comprobamos si está
	ordenado o si hay que hacer algunos movimientos finales para que el
	primer número quede en la primera posición del A. */
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
			push_a(stack_a, stack_b, 1);
		else
		{
			candidate = cost_calculator(stack_a, stack_b);
			if (check_double_movements(stack_a, stack_b, candidate) == 0)
			{
				stack_a_moves(stack_a, stack_b, candidate);
				stack_b_moves(stack_b, candidate);
			}
			push_a(stack_a, stack_b, 1);
		}
		debug_print_value(stack_a, "value");
		debug_print_value(stack_b, "value");
		count--;
	}
	if (stack_is_sorted(stack_a) == 1)
		return ;
	final_sort(stack_a);
}

/* Calculamos los costes de mover cada número (posición) en B (y en A según
el número de B). */
int	cost_calculator(t_stack *stack_a, t_stack *stack_b)
{
	int	candidate;

	candidate = cost_calculator_calculates(stack_a, stack_b, &candidate);
	return (candidate);
}

/* Función que continúa la anterior. Calculamos el coste de mover
cada número en B y en A. La primera suma más pequeña de los costes la tomará
total_cost y el candidato cogerá esa posición. */
int	cost_calculator_calculates(t_stack *stack_a, t_stack *stack_b, int *candidate)
{
	int	i;
	int	total_cost;

	i = 0;
	total_cost = stack_a->size;
	while (i < stack_b->new_size)
	{
		if (i <= (stack_b->new_size / 2 + 1))
			stack_b->cost_b = i;
		else
			stack_b->cost_b = (stack_b->new_size - i);
		if (stack_a->pos[stack_b->target_pos[i]] <= (stack_a->new_size / 2 + 1))
			stack_a->cost_a = stack_b->target_pos[i];
		else
			stack_a->cost_a = (stack_a->new_size
					- stack_a->pos[stack_b->target_pos[i]]);
		if (total_cost > stack_a->cost_a + stack_b->cost_b)
		{
			total_cost = stack_a->cost_a + stack_b->cost_b;
			*candidate = stack_b->pos[i];
		}
		i++;
	}
	return (*candidate);
}

/* Con el candidato resultante de cost_calculator,
volvemos a calcular los costes de cada stack para comprobar
si en ambos es negativo o positivo y podemos ahorrar movimientos
(es decir: en cada pila coincide que deben moverse hacia arriba o
hacia abajo). Si es negativo: rrr; si es positivo en ambos, rr. */
int	check_double_movements(t_stack *stack_a, t_stack *stack_b, int candidate)
{
	if (candidate <= (stack_b->new_size / 2 + 1))
		stack_b->cost_b = candidate;
	else
		stack_b->cost_b = (candidate - stack_b->new_size);
	if (stack_a->pos[stack_b->target_pos[candidate]] <= (stack_a->new_size / 2 + 1))
		stack_a->cost_a = stack_b->target_pos[candidate];
	else
		stack_a->cost_a = (stack_a->pos[stack_b->target_pos[candidate]] - stack_a->new_size);
	if (stack_a->cost_a < 0 && stack_b->cost_b < 0)
	{
		do_rrr(stack_a, stack_b);
		return (1);
	}
	else if (stack_a->cost_a > 0 && stack_b->cost_b > 0)
	{
		do_rr(stack_a, stack_b);
		return (1);
	}
	return (0);
}

/* Subfunción para ahorrar movimientos haciendo rrr las veces
que coincidan ambos stacks. Los movimientos restantes serán individuales */
void	do_rrr(t_stack *stack_a, t_stack *stack_b)
{
	while (stack_a->cost_a < 0 && stack_b->cost_b < 0)
	{
		rrr(stack_a, stack_b, 1);
		stack_a->cost_a++;
		stack_b->cost_b++;
	}
	while (stack_a->cost_a < 0)
	{
		reverse_rotate_a(stack_a, 1);
		stack_a->cost_a++;
	}
	while (stack_b->cost_b < 0)
	{
		reverse_rotate_b(stack_b, 1);
		stack_b->cost_b++;
	}
}
