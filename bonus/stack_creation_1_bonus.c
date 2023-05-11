/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_creation_1_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvallejo <cvallejo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 17:43:26 by cvallejo          #+#    #+#             */
/*   Updated: 2023/05/10 12:52:35 by cvallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker_bonus.h"

/*Pasamos la estructura por referencia (puntero a la estructura).
Para movernos por ella, usamos -> (como en las listas).
Es equivalente a (*stack_a).value. Calculamos su value, index y size*/
void	stack_a_creation(t_stack *stack_a, int *numbers, char **split_av)
{
	stack_a->value = malloc(sizeof(int) * strlen_split(split_av));
	if (!stack_a->value)
		print_error();
	stack_a->index = malloc(sizeof(int) * strlen_split(split_av));
	if (!stack_a->index)
		print_error();
	stack_a->size = strlen_split(split_av);
	stack_a->new_size = strlen_split(split_av);
	stack_value(stack_a, numbers);
	stack_index(stack_a);
}

/*Pasamos la estructura por referencia (puntero a la estructura).
Para movernos por ella, usamos -> (como en las listas).
Es equivalente a (*stack_a).value. Calculamos su size, new_size, value
y index*/
void	stack_b_creation(t_stack *stack_a, t_stack *stack_b)
{
	stack_b->size = stack_a->size - 3;
	stack_b->new_size = 0;
	stack_b->value = malloc(sizeof(int) * stack_b->size);
	if (!stack_b->value)
		print_error();
	stack_b->index = malloc(sizeof(int) * stack_b->size);
	if (!stack_b->index)
		print_error();
	stack_b->pos = NULL;
	stack_b->target_pos = NULL;
}

/*Introducimos en la estructura el valor de cada número*/
void	stack_value(t_stack *stack_a, int *numbers)
{
	int	i;

	i = 0;
	while (i < stack_a->size)
	{
		stack_a->value[i] = numbers[i];
		i++;
	}
}

/*Introducimos en el stack la posición que
ocupa de mayor a menor, cuando pasemos números de
stack a stack new_size vendrá reducido o aumentado*/
void	stack_index(t_stack *stack_origin)
{
	int	i;
	int	j;
	int	pos;

	i = 0;
	while (i < stack_origin->new_size)
	{
		j = 0;
		pos = 1;
		while (j < stack_origin->new_size)
		{
			if (stack_origin->value[i] > stack_origin->value[j])
				pos++;
			j++;
		}
		stack_origin->index[i] = pos;
		i++;
	}
}
