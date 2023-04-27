/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvallejo <cvallejo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 12:57:51 by cvallejo          #+#    #+#             */
/*   Updated: 2023/04/26 12:23:14 by cvallejo         ###   ########.fr       */
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
