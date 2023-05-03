/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvallejo <cvallejo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 10:58:13 by cvallejo          #+#    #+#             */
/*   Updated: 2023/05/02 15:58:39 by cvallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Función para filtrar qué ordenación debe hacer el programa
dependiendo de la cantidad de números recibidos */
void	sort_numbers(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->new_size == 2)
		sort_2(stack_a);
	else if (stack_a->new_size == 3)
		sort_3(stack_a);
	else
		sort_4_or_more(stack_a, stack_b);
}

/* Con 2 números sólo habría dos posibilidades:
1) El primer número es mayor: ya está ordenado
2) El segundo número es mayor: se hace swap_a */
void	sort_2(t_stack *stack_a)
{
	int	i;

	if (stack_a->index[0] < stack_a->index[1])
		return ;
	else
		swap_a(stack_a, 1);
}

/* Para ordenar 3 números tenemos que tener en cuenta las 6 posibilidades:
1 2 3 | 1 3 2 | 2 1 3 | 2 3 1 | 3 1 2 | 3 2 1 */
void	sort_3(t_stack *stack_a)
{
	sort_3_cases_1_to_3(stack_a);
	sort_3_cases_4_to_6(stack_a);
}

/* Pasamos todos los números a B excepto 3 que quedan en A. Nos aseguramos que
quedan arriba de B los que tienen menos valor, ¿cómo? Haciendo ra a los valores
que sobrepasan la mitad del index total.
Luego, vamos pasando de 3 en 3 los números a A */
void	sort_4_or_more(t_stack *stack_a, t_stack *stack_b)
{
	int	i;

	if (stack_is_sorted(stack_a) == 1)
		return ;
	stack_b->size = stack_a->size - 3;
	stack_b->new_size = 0;
	stack_b->value = malloc(sizeof(int) * stack_b->size);
	stack_b->index = malloc(sizeof(int) * stack_b->size);
	stack_b->pos = NULL;
	stack_b->target_pos = NULL;
	i = 0;
	while (i < stack_a->size - 3)
	{
		if (stack_a->index[0] <= stack_a->size - 3)
		{
			push_b(stack_a, stack_b);
			i++;
		}
		else
			rotate_a(stack_a, 1);
	}
	sort_3(stack_a);
	stack_b_to_stack_a(stack_a, stack_b);
	free_stack(stack_b);
}
