/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvallejo <cvallejo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 16:44:12 by cvallejo          #+#    #+#             */
/*   Updated: 2023/04/27 10:20:50 by cvallejo         ###   ########.fr       */
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
		return (0);
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
	else if (ac > 2)
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
void	ft_exit(void)
{
	system("leaks push_swap");
}
int	main(int ac, char **av)
{
	t_stack	stack_a;
	t_stack	stack_b;
	int		*numbers;
	char	**split_av;
	int		i;

	atexit(ft_exit);
	split_av = check_params(ac, av);
	if (split_av == NULL)
		return (0);
	i = 0;
	numbers = set_params(ac, split_av);  
	//stack creation
	stack_a_creation(&stack_a, numbers, split_av);
	sort_numbers(&stack_a, &stack_b); 
	/*i = 0;
	while (stack_a.value[i])
	{
		ft_printf("%d\n", stack_a.value[i]);
		i++;
	}
	ft_printf("Size:%d - ", stack_a.size);*/
	free(numbers);
	free(stack_a.value);
	free(stack_a.index);
	free(stack_a.pos);
	free(stack_b.value);
	free(stack_b.index);
	free(stack_b.pos);
	free(stack_b.target_pos);
	return (0);
}
