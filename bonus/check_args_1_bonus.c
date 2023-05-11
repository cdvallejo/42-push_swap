/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvallejo <cvallejo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 12:10:55 by cvallejo          #+#    #+#             */
/*   Updated: 2023/05/11 15:49:14 by cvallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
	int	count;

	count = i;
	while (count < ac)
	{
		while (split_av[count] != NULL)
		{
			if (is_number(split_av[count]) == 0)
				print_error();
			count++;
		}
	}
	check_int(split_av, i);
	if (count == 1)
		free_memory(split_av);
}

//Comprobamos que no pasa del MIN_VALUE y MAX_VALUE de un int
void	check_int(char **split_av, int i)
{
	long	num;

	while (split_av[i])
	{
		num = (ft_long_atoi(split_av[i]));
		if (num < -2147483648
			|| num > 2147483647
			|| check_zeros_maxlen(split_av[i]) == 0)
			print_error();
		i++;
	}
}
