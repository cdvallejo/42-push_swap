/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvallejo <cvallejo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 16:44:12 by cvallejo          #+#    #+#             */
/*   Updated: 2023/05/03 16:56:22 by cvallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*Comprobamos sus argumentos (si es 2 debe ser un string)
y los pasamos por las funciones parseadoras. Retornamos
un doble puntero con los números limpios y separados*/
char	**check_params(int ac, char **av)
{
	char	**split_av;
	int		i;

	i = 0;
	if (ac == 1)
		return (NULL);
	else if (ac == 2)
	{
		i = 0;
		split_av = ft_split(av[1], ' ');
		ac = strlen_split(split_av);
		if (ac == 1)
		{
			check_ac(ac, split_av, 0);
			return (NULL);
		}
		check_ac(ac, split_av, i);
	}
	else
	{
		i = 1;
		check_ac(ac, av, i);
		split_av = ++av;
	}
	return (split_av);
}

//Comprueba que los parámetros están bien
void	check_ac(int ac, char **split_av, int i)
{
	check_number(ac, split_av, i);
	check_repeat_number(ac, split_av, i);
	check_int(ac, split_av, i);
}

