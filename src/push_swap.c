/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvallejo <cvallejo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 16:44:12 by cvallejo          #+#    #+#             */
/*   Updated: 2023/05/10 17:15:29 by cvallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
}

/* Nuestro programa comienza asignando los dos stacks A y B.
Según los argumentos recibidos, tomaremos con check_params la cantidad
de números recibidos.
Con sort_numbers, ordenamos A.
Finalmente, liberamos la memoria usada que aún estaba siendo alocada */
int	main(int ac, char **av)
{
	t_stack	stack_a;
	t_stack	stack_b;
	int		*numbers;
	char	**split_av;

	split_av = check_params(ac, av);
	if (split_av == NULL || (strlen_split(split_av) == 0))
	{
		free(split_av);
		return (0);
	}
	numbers = set_params(ac, split_av);
	stack_a_creation(&stack_a, numbers, split_av);
	if (ac == 2)
		free_memory(split_av);
	free(numbers);
	sort_numbers(&stack_a, &stack_b);
	free_stack(&stack_a);
	return (0);
}
	//system("leaks push_swap");
	//debug_leaks();
	//debug_print_stack(&stack_a, "A");