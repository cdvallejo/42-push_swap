/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cvallejo <cvallejo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 10:58:13 by cvallejo          #+#    #+#             */
/*   Updated: 2023/04/27 14:14:13 by cvallejo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_numbers(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->new_size == 2)
		sort_2(stack_a);
	else if (stack_a->new_size == 3)
		sort_3(stack_a);
	else
		sort_4_or_more(stack_a, stack_b);
}

/*Con 2 números sólo habría dos posibilidades: 
1) El primer número es mayor: ya está ordenado
2) El segundo número es mayor: se hace swap_a*/
void	sort_2(t_stack *stack_a)
{
	int	i;

	if (stack_a->index[0] < stack_a->index[1])
		return ;
	else
		swap_a(stack_a, 1);
}

/*Para ordenar 3 números tenemos que tener en cuenta las 6 posibilidades: 
1 2 3 | 1 3 2 | 2 1 3 | 2 3 1 | 3 1 2 | 3 2 1*/
void	sort_3(t_stack *stack_a)
{
	if (stack_a->index[0] < stack_a->index[1] && stack_a->index[1] < stack_a->index[2] && stack_a->index[0] < stack_a->index[2])
		return ;
	else if (stack_a->index[0] < stack_a->index[1] && stack_a->index[1] > stack_a->index[2] && stack_a->index[0] < stack_a->index[2])
	{
		reverse_rotate_a(stack_a, 1);
		swap_a(stack_a, 1);
	}
	else if (stack_a->index[0] > stack_a->index[1] && stack_a->index[1] < stack_a->index[2] && stack_a->index[0] < stack_a->index[2])
		swap_a(stack_a, 1);
	else if (stack_a->index[0] < stack_a->index[1] && stack_a->index[1] > stack_a->index[2] && stack_a->index[0] > stack_a->index[2])
		reverse_rotate_a(stack_a, 1);
	else if (stack_a->index[0] > stack_a->index[1] && stack_a->index[1] < stack_a->index[2] && stack_a->index[0] > stack_a->index[2])
		rotate_a(stack_a, 1);
	if (stack_a->index[0] > stack_a->index[1] && stack_a->index[1] > stack_a->index[2] && stack_a->index[0] > stack_a->index[1])
	{
		rotate_a(stack_a, 1);
		swap_a(stack_a, 1);
	}
	ft_printf("Check stack_a:\n");
	int i = 0;
	while (i < stack_a->new_size)
	{
		ft_printf("Value: %d\n", stack_a->value[i]);
		i++;
	}
	i = 0;
	while (i < stack_a->new_size)
	{
		ft_printf("Index: %d\n", stack_a->index[i]);
		i++;
	}
}

/*Pasamos todos los números a B excepto 3 que quedan en A. Nos aseguramos de que quedan arriba de B
los que tienen menos valor, ¿cómo? Haciendo ra a los valores que sobrepasan la mitad del index total.
Luego, vamos pasando de 3 en 3 los números a A*/
void	sort_4_or_more(t_stack *stack_a, t_stack *stack_b)
{
	int i;
	int j;
	
	if (stack_is_sorted(stack_a) == 1)
		return ;
	stack_b->size = stack_a->size - 3;
	stack_b->new_size = 0;
	stack_b->value = malloc(sizeof(int) * stack_b->size);
	stack_b->index = malloc(sizeof(int) * stack_b->size);
	i = 0;
	while(i < stack_a->size - 3)
	{
		if (stack_a->index[0] <= stack_a->size - 3)
		{
			ft_printf("OJO: Hacemos push de index %d a B\n", stack_a->index[0]);
			push_b(stack_a, stack_b);
			i++;
		}
		else
			rotate_a(stack_a, 1);
	}
	sort_3(stack_a);
	//Comprobaciones
	ft_printf("CHECK stack_a:\n");
	i = 0;
	while (i < stack_a->new_size)
	{
		ft_printf("Index: %d\n", stack_a->index[i]);
		i++;
	}
	ft_printf("----Size: %d - \n", stack_a->new_size);
	ft_printf("CHECK stack_b:\n");
	i = 0;
	while (i < stack_b->new_size)
	{
		ft_printf("Index: %d\n", stack_b->index[i]);
		i++;
	}
	ft_printf("----Size: %d - \n", stack_b->new_size);
	ft_printf("POSICIONES ACTUALES DE A:\n");
	stack_positions(stack_a);
	ft_printf("POSICIONES ACTUALES DE B:\n");
	stack_positions(stack_b);
	ft_printf("TARGET POS DE B para A:\n");
	target_position(stack_a, stack_b);
	ft_printf("EMPEZAMOS A LLEVAR TODO A STACK_A\n");
	i = 0;
	ft_printf("-----TARGET POS DE B para A:\n");
	while(i < stack_b->new_size)
	{
		ft_printf("TARGET_POS: %d\n", stack_b->target_pos[i]);
		i++;
	}
	stack_b_to_stack_a(stack_a, stack_b);
	int count;
	/*while(i < stack_b->new_size)
	{
		if (stack_b->index[i] <= (stack_b->new_size / 2))
			cost_b = stack_b->index[i];
		else
			cost_b = (stack_b->index[i] - stack_b->new_size) * -1;
		if (stack_a->index[stack_b->target_pos[i]] <= (stack_a->new_size / 2))
			cost_a = stack_b->target_pos[i];
		else
			cost_a = (stack_a->[stack_b->target_pos[i]] - stack_a->new_size) * -1;
		if (cost_a < 0 && cost_b < 0)
		{
			rrr(*stack_a, *stack_b);
			target_position(stack_a, stack_b);
		}
		else if (cost_a > 0 && cost_a > 0)
		{
			rr(*stack_, *stack_b);
			target_position(stack_a, stack_b);
		}
		if (total_cost > cost_a + cost_b)
		{
			total_cost = cost_a + cost_b;
			candidate = stack_b->index[i];
		}
		i++;
	}*/
	/*ft_printf("PUSH_A\n");
	push_a(stack_a, stack_b);
	target_position(stack_a, stack_b);
	ft_printf("CHECK stack_a:\n");
	i = 0;
	while (i < stack_a->new_size)
	{
		ft_printf("Index: %d\n", stack_a->index[i]);
		i++;
	}
	ft_printf("----Size: %d - \n", stack_a->new_size);
	ft_printf("CHECK stack_b:\n");
	i = 0;
	while (i < stack_b->new_size)
	{
		ft_printf("Index: %d\n", stack_b->index[i]);
		i++;
	}
	ft_printf("----Size: %d - \n", stack_b->new_size);
	ft_printf("POSICIONES ACTUALES DE A:\n");
	stack_positions(stack_a);
	ft_printf("POSICIONES ACTUALES DE B:\n");
	stack_positions(stack_b);
	ft_printf("TARGET POS DE B para A:\n");
	target_position(stack_a, stack_b);*/
}


