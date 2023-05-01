/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvallejo <cvallejo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 12:10:55 by cvallejo          #+#    #+#             */
/*   Updated: 2023/05/01 10:57:14 by cvallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*Comprobamos que no exista un primer elemento vacío (primera condición), ni
que '-', '+' no sean un único elemento del array (segunda condición:
no deja incrementar el contador en el caso de que ese signo dé como
resultado 1 (un único caracter) al no aumentar el contador,
pasa el signo a !ft_isdigit*/
int	is_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '\0')
	{
		print_error();
	}
	if ((str[i] == '-' || str[i] == '+') && (ft_strlen(str) > 1))
		i++;
	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

/*Comprobamos que los parámetros son números, y si resulta que al final se trata
de un único número, el programa no hace nada.*/
void	check_number(int ac, char **split_av, int i)
{
	while (i < ac)
	{
		while (split_av[i] != NULL)
		{
			if (is_number(split_av[i]) == 0)
				print_error();
			i++;
		}
	}
	if (i == 1)
		free_memory(split_av);
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

//Comprobamos que no pasa del MIN_VALUE y MAX_VALUE de un int
void	check_int(int ac, char **split_av, int i)
{
	while (split_av[i])
	{
		if ((ft_long_atoi(split_av[i]) < -2147483648)
			|| (ft_long_atoi(split_av[i]) > 2147483647))
			print_error();
		i++;
	}
}
