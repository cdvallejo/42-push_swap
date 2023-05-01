/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvallejo <cvallejo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 12:57:51 by cvallejo          #+#    #+#             */
/*   Updated: 2023/05/01 15:52:37 by cvallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	free(stack_origin->target_pos);
}
