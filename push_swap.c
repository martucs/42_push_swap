/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2push_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <martalop@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 20:43:49 by martalop          #+#    #+#             */
/*   Updated: 2024/04/21 14:34:31 by martalop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
#include <string.h>

int	ft_atoi(char *str, int *flag)
{
	int		indx;
	long	suma;
	int		signo;

	indx = 0;
	suma = 0;
	signo = 1;
	while (str[indx] == 32 || (str[indx] >= 9 && str[indx] <= 13))
		indx++;
	if (str[indx] == '-' || str[indx] == '+')
	{
		if (str[indx] == '-')
			signo = signo * -1;
		indx++;
	}
	while (str[indx] >= '0' && str[indx] <= '9')
	{
		suma = suma * 10 + (str[indx] - '0');
		indx++;
		if (signo * suma > 2147483647 || signo * suma < -2147483648)
			return (*flag = 1, 0);
	}
	if ((indx > 0 && (str[indx - 1] < '0')) || str[indx] != '\0')
		*flag = 1;
	return (suma * signo);
}

//	if ((signo == 1 && suma > 2147483647) || (signo == -1 && suma > 2147483648))

t_list	*create_empty_node(void)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->num = 0;
	new->index = 0;
	new->cost = 0;
	new->target = NULL;
	new->next = NULL;
	return (new);
}

int	check_list_num(int num, t_list *stack)
{
	if (!stack)
		return (0);
	while (stack)
	{
		if (stack->num == num)
			return (1);
		stack = stack->next;
	}
	return (0);
}

t_list	*arg_check(char **arg)
{
	int		x;
	int		flag;
	t_list	*stack;
	t_list	*node;

	x = 1;
	flag = 0;
	stack = NULL;
	while (arg[x])
	{
		node = create_empty_node();
		if (node == NULL)
			return (free_list(stack), NULL);
		node->num = ft_atoi(arg[x], &flag);
		if (flag == 1 || check_list_num(node->num, stack) == 1 || !arg[x][0])
		{
			free_list(stack);
			free(node);
			return (NULL);
		}
		add_node_to_list(node, &stack);
		x++;
	}
	return (stack);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (1);
	stack_a = arg_check(argv);
	if (!stack_a)
		return (write(2, "Error\n", 6), 1);
	if (check_order(stack_a) == 0)
		return (free_list(stack_a), 0);
	else
	{
		if (argc == 3)
			two_nums(&stack_a);
		else if (argc == 4)
			three_nums(&stack_a);
		else if (argc > 4)
			sort_nums(&stack_a, &stack_b, argc);
	}
	free_list(stack_a);
	free_list(stack_b);
	return (0);
}
