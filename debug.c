#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include "push_swap.h"

#define DEBUG 0

#define CYAN "\x1b[36m"
#define GREEN "\x1b[32m"
#define RED "\x1b[31m"
#define WHITE "\x1b[1;37m"
#define RESET "\x1b[0m"

#define DBG "\x1b[1;36m[DEBUG]\x1b[0m"

static void	ft_exit(void)
{
	system("leaks -q push_swap");
}

void	debug_leaks(void)
{
	if (DEBUG)
		atexit(ft_exit);
}

static void	print_prompt(void)
{
	printf("%s %s", DBG, WHITE);
}

void	debug_print(char *message, ...)
{
	va_list	args;

	if (DEBUG)
	{
		print_prompt();
		va_start(args, message);
		vprintf(message, args);
		va_end(args);
		printf("%s", RESET);
		fflush(stdout);
	}
}

void	debug_print_stack(t_stack *stack, char *name)
{
	int	i;

	if (!DEBUG)
		return ;
	i = 0;
	print_prompt();
	printf("%s = [", name);
	while (i < stack->new_size)
	{
		printf(" %i", stack->index[i]);
		i++;
	}
	printf(" ]\n");
	printf("%s", RESET);
	fflush(stdout);
}

void	debug_print_pos(t_stack *stack, char *name)
{
	int	i;

	if (!DEBUG)
		return ;
	i = 0;
	print_prompt();
	printf("%s = [", name);
	while (i < stack->new_size)
	{
		printf(" %i", stack->pos[i]);
		i++;
	}
	printf(" ]\n");
	printf("%s", RESET);
	fflush(stdout);
}

void	debug_print_value(t_stack *stack, char *name)
{
	int	i;

	if (!DEBUG)
		return ;
	i = 0;
	print_prompt();
	printf("%s = [", name);
	while (i < stack->new_size)
	{
		printf(" %i", stack->value[i]);
		i++;
	}
	printf(" ]\n");
	printf("%s", RESET);
	fflush(stdout);
}
