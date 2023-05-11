/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_creation_2_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvallejo <cvallejo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 17:43:26 by cvallejo          #+#    #+#             */
/*   Updated: 2023/05/10 12:53:39 by cvallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker_bonus.h"

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

	free_target_pos(stack_b);
	stack_b->target_pos = malloc(sizeof(int) * stack_b->new_size);
	if (!stack_b->target_pos)
		print_error();
	i = 0;
	while (i < stack_b->new_size)
	{
		j = 0;
		aux = stack_a->index[stack_a->new_size - 1];
		while (j < stack_a->new_size)
		{
			if ((stack_b->index[i] < stack_a->index[j]
					&& stack_b->index[i] > aux)
				|| ((stack_b->index[i] > aux || stack_b->index[i]
						< stack_a->index[j]) && aux > stack_a->index[j]))
				stack_b->target_pos[i] = j;
			aux = stack_a->index[j];
			j++;
		}
		i++;
	}
}

//Si target_pos de B tiene memoria, la vacía para recalcular
void	free_target_pos(t_stack	*stack_b)
{
	if (stack_b->target_pos != NULL)
		free_memory_int(stack_b->target_pos);
}
