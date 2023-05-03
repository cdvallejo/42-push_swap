/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvallejo <cvallejo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 12:57:51 by cvallejo          #+#    #+#             */
/*   Updated: 2023/05/02 15:26:22 by cvallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	print_error(void)
{
	write(2, "Error\n", 6);
	exit(0);
}

void	free_memory(char **function)
{
	int	i;

	i = 0;
	while (function[i])
	{
		free(function[i]);
		i++;
	}
	free(function);
}

void	free_memory_int(int *function)
{
	free(function);
}

void	free_stack(t_stack *stack_origin)
{
	free(stack_origin->value);
	free(stack_origin->index);
	free(stack_origin->pos);
	if (stack_origin->target_pos != NULL)
		free(stack_origin->target_pos);
}
