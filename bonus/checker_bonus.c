/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvallejo <cvallejo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 10:37:23 by cvallejo          #+#    #+#             */
/*   Updated: 2023/05/10 17:02:13 by cvallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker_bonus.h"

/*Función que identifica la clase de operación introducida y la realiza*/
static bool	sort_line(t_stack *stack_a, t_stack *stack_b, char *line)
{
	if (ft_strncmp("sa\n", line, 3) == 0)
		swap_a(stack_a, 0);
	else if (ft_strncmp("sb\n", line, 3) == 0)
		swap_b(stack_b, 0);
	else if (ft_strncmp("ss\n", line, 3) == 0)
		ss(stack_a, stack_b, 0);
	else if (ft_strncmp("pa\n", line, 3) == 0)
		push_a(stack_a, stack_b, 0);
	else if (ft_strncmp("pb\n", line, 3) == 0)
		push_b(stack_a, stack_b, 0);
	else if (ft_strncmp("ra\n", line, 3) == 0)
		rotate_a(stack_a, 0);
	else if (ft_strncmp("rb\n", line, 3) == 0)
		rotate_b(stack_b, 0);
	else if (ft_strncmp("rr\n", line, 3) == 0)
		rr(stack_a, stack_b, 0);
	else if (ft_strncmp("rra\n", line, 4) == 0)
		reverse_rotate_a(stack_a, 0);
	else if (ft_strncmp("rrb\n", line, 4) == 0)
		reverse_rotate_b(stack_b, 0);
	else if (ft_strncmp("rrr\n", line, 4) == 0)
		rrr(stack_a, stack_b, 0);
	else
		return (false);
	return (true);
}

/*Función que lee a medida que se van introduciendo parámetros.
En caso de leer un parámetro erróneo, imprime error y sale*/
static void	read_line(t_stack *stack_a, t_stack *stack_b)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		if (sort_line(stack_a, stack_b, line) == true)
		{
			free(line);
			line = get_next_line(0);
		}
		else
			print_error();
	}
	if (stack_is_sorted(stack_a) == 1)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
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
	stack_b_creation(&stack_a, &stack_b);
	read_line(&stack_a, &stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
