/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_params.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvallejo <cvallejo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 12:20:14 by cvallejo          #+#    #+#             */
/*   Updated: 2023/05/01 10:56:42 by cvallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*Rellena el array de int convirtiendo los argumentos string a int
dependiendo de si era una cadena o no*/
int	*set_params(int ac, char **split_av)
{
	int	*numbers;

	if (ac == 2)
		numbers = set_params_string(ac, split_av, numbers);
	else
		numbers = set_params_no_string(ac, split_av, numbers);
	return (numbers);
}

int	*set_params_string(int ac, char **split_av, int *numbers)
{
	int	i;

	numbers = (int *)malloc(sizeof(int) * strlen_split(split_av));
	if (!numbers)
		return (NULL);
	i = 0;
	while (split_av[i])
	{
		numbers[i] = ft_long_atoi(split_av[i]);
		i++;
	}
	free_memory(split_av);
	return (numbers);
}

int	*set_params_no_string(int ac, char **split_av, int *numbers)
{
	int	i;
	int	j;

	numbers = (int *)malloc(sizeof(int) * ac - 1);
	if (!numbers)
		return (NULL);
	i = 0;
	j = 0;
	while (j < ac -1)
	{
		numbers[i] = ft_long_atoi(split_av[j]);
		i++;
		j++;
	}
	i = 0;
	return (numbers);
}
