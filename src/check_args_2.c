/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvallejo <cvallejo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 12:10:55 by cvallejo          #+#    #+#             */
/*   Updated: 2023/05/11 16:22:27 by cvallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*Función que tiene en cuenta la longitud máxima de cifras en caso
de que introduzcan un número más largo que un long (long_atoi no contempla
un número de muchas cifras). Teniendo en cuenta también si escriben ceros
delante*/
int	check_zeros_maxlen(char *str)
{
	int	i;
	int	count_dig;

	i = 0;
	count_dig = 0;
	while (str[i])
	{
		if (str[i] == '+' || str[i] == '-')
			i++;
		while (str[i] == '0')
			i++;
		while (str[i])
		{
			count_dig++;
			i++;
		}
	}
	if (count_dig > 10)
		return (0);
	else
		return (1);
}

/*En el caso de recibir un String al que le hemos pasado un split,
contamos cuántos números tiene*/
int	strlen_split(char **split_av)
{
	int	i;

	i = 0;
	while (split_av[i] != NULL)
		i++;
	return (i);
}

//Comprobamos si se repite algún número
int	check_repeat_number(int ac, char **av, int i)
{
	int	j;

	while (i < ac)
	{
		j = i + 1;
		while (j < ac)
		{
			if (ft_long_atoi(av[i]) == ft_long_atoi(av[j]))
				print_error();
			j++;
		}
		i++;
	}
	return (0);
}
