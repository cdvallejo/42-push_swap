/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_creation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvallejo <cvallejo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 17:43:26 by cvallejo          #+#    #+#             */
/*   Updated: 2023/05/01 14:20:10 by cvallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*Introducimos en la estructura el valor de cada númmero*/
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

/*Pasamos la estructura por referencia (puntero a la estructura).
Para movernos por ella, usamos -> (como en las listas).
Es equivalente a (*stack_a).value. Calculamos su value, index y size*/
void	stack_a_creation(t_stack *stack_origin, int *numbers, char **split_av)
{
	stack_origin->value = malloc(sizeof(int) * strlen_split(split_av));
	stack_origin->index = malloc(sizeof(int) * strlen_split(split_av));
	stack_origin->size = strlen_split(split_av);
	stack_origin->new_size = strlen_split(split_av);
	stack_value(stack_origin, numbers);
	stack_index(stack_origin);
}

/*Función que indica la posición de cada número del array (desde 0)*/
void	stack_positions(t_stack *stack_origin)
{
	int	i;

	if (stack_origin->pos != 0)
		free_memory_int(stack_origin->pos);
	stack_origin->pos = malloc(sizeof(int) * stack_origin->new_size);
	i = 0;
	while (i < stack_origin->new_size)
	{
		stack_origin->pos[i] = i;
		i++;
	}
}

/*Función que indica la posición que debería ocupar cada número de stack_b
en stack_a
Cada num en stack_b recorre stack_b comprobando si su index es mayor.
Si es así, guardamos su posición en aux y establecemos su target_pos.
Comprobamos que aux guarde siempre el valor más alto que precede al num de b,
así como su target_pos*/
void	target_position(t_stack *stack_a, t_stack *stack_b)
{
	int	i;
	int	j;
	int	aux;

	if (stack_b->target_pos != 0)
		free_memory_int(stack_b->target_pos);
	stack_b->target_pos = malloc(sizeof(int) * stack_b->new_size);
	i = 0;
	while (i < stack_b->new_size)
	{
		j = 0;
		aux = stack_a->index[stack_a->new_size - 1];
		while (j < stack_a->new_size)
		{
			if ((stack_b->index[i] < stack_a->index[j]
					&& stack_b->index[i] > aux)
				|| ((stack_b->index[i] > aux
						|| stack_b->index[i] < stack_a->index[j])
					&& aux > stack_a->index[j]))
				stack_b->target_pos[i] = j;
			aux = stack_a->index[j];
			j++;
		}
		i++;
	}
}

/*Función que comprueba si el stack está ordenado*/
int	stack_is_sorted(t_stack *stack_a)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < stack_a->size)
	{
		j = i + 1;
		while (j < stack_a->size)
		{
			if (stack_a->index[i] < stack_a->index[j])
				j++;
			else
				return (0);
		}
		i++;
	}
	return (1);
}
