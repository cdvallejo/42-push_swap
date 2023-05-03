/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_params.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvallejo <cvallejo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 12:20:14 by cvallejo          #+#    #+#             */
/*   Updated: 2023/05/02 17:23:56 by cvallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Rellena el array de int convirtiendo los argumentos string a int
Lo hará con una función u otra, dependiendo de si era una cadena o no */
int	*set_params(int ac, char **split_av)
{
	int	*numbers;

	if (ac == 2)
		numbers = set_params_string(ac, split_av, numbers);
	else
		numbers = set_params_no_string(ac, split_av, numbers);
	return (numbers);
}

/* Si el argumento era un string, metemos en el array numbers
cada número que estaba en split_av y lo liberamos (ya no hará falta). */
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

/* Si el argumento no era un string, alocamos memoria según el número
de argumentos en el array de int numbers. Metemos en él los números que
estaban en split_av y lo liberamos (ya no hará falta).*/
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
	return (numbers);
}
