/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvallejo <cvallejo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 10:37:23 by cvallejo          #+#    #+#             */
/*   Updated: 2023/05/03 16:13:32 by cvallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"


/* Nuestro programa comienza asignando los dos stacks A y B.
Según los argumentos recibidos, tomaremos con check_params la cantidad
de números recibidos.
Con sort_numbers, ordenamos A.
Finalmente, liberamos la memoria usada que aún estaba siendo alocada*/

static bool sort_line(t_stack *stack_a, t_stack *stack_b, char *line)
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
        rotate_b(stack_a, 0);
    else if (ft_strncmp("rr\n", line, 3) == 0)
        rr(stack_a, stack_b, 0);
    else if (ft_strncmp("rra\n", line, 4) == 0)
        reverse_rotate_a(stack_a, 0);
    else if (ft_strncmp("rrb\n", line, 4) == 0)
        reverse_rotate_b(stack_a, 0);
    else if (ft_strncmp("rrr\n", line, 4) == 0)
        rrr(stack_a, stack_b, 0);
    else
        return (false);
    return (true);
}

static void read_line(t_stack *stack_a, t_stack *stack_b)
{
    char   *line;

    line = get_next_line(0);
    while (line)
    {
        sort_line(stack_a, stack_b, line);
        free(line);
        line = get_next_line(0);
    }
    if (stack_is_sorted(stack_a) == 1)
		fr_printf("OK\n");
    else
        ft_printf("KO\n");
}

int	main(int ac, char **av)
{
	t_stack	stack_a;
	t_stack	stack_b;
	int		*numbers;
	char	**split_av;
	int		i;

	debug_leaks();
	split_av = check_params(ac, av);
	if (split_av == NULL)
		return (0);
	i = 0;
	numbers = set_params(ac, split_av);
    if (strlen_split(numbers) > 3)
    {
        stack_a_creation(&stack_a, numbers, split_av);
        stack_b_creation(&stack_a, &stack_b);
    }
	else
        stack_a_creation(&stack_a, numbers, split_av);
    free(numbers);
    read_op(&stack_a, &stack_b);
	free_stack(&stack_a);
    free_stack(&stack_b);
	return (0);
}
