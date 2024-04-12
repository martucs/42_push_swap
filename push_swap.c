/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2push_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <martalop@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 20:43:49 by martalop          #+#    #+#             */
/*   Updated: 2024/04/12 15:36:35 by martalop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
#include <stdio.h>

int	ft_atoi(char *str, int *flag)
{
	int	indx;
	long	suma;
	int	signo;

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
	//	if ((signo == 1 && suma > 2147483647) || (signo == -1 && suma > 2147483648))
		if (signo * suma > 2147483647 || signo * suma < -2147483648)
		{
			*flag = 1;
			return (0);
		}
	}
 	if ((indx > 0 && (str[indx - 1] < '0')) || str[indx] != '\0')
		*flag = 1;
	return (suma * signo);
}

t_list	*create_empty_node(void)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return(NULL);
	new->num = 0;
	new->index = 0;
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

void	add_node_to_list(t_list *node, t_list **dir_stack)
{
	t_list	*aux;

	if (*dir_stack == NULL)
	{
		*dir_stack = node;
		return ;
	}
	aux = *dir_stack;
	while (aux->next != NULL)
	{
		aux = aux->next;
	}
	aux->next = node;
	node->next = NULL;
}

void	free_list(t_list *list)
{
	t_list	*tmp;

	tmp = list;
	/*while (tmp != NULL)
	{
		tmp = tmp->next;
		free(list);
		list = tmp;
	}
*/
	while (list)
	{
		tmp = list->next;
		free(list);
		list = tmp;
	}
}


t_list	*arg_check(char **arg)
{
	int	x;
	int	flag;
	t_list	*stack;
	t_list	*node;

	x = 1;
	flag = 0;
	stack = NULL;
	while (arg[x])
	{
		//	printf("res atoi: %d\n", ft_atoi(arg[x], &flag));
		node = create_empty_node();
		if (node == NULL)
		{
			free_list(stack);
			return (NULL);
		}
		node->num = ft_atoi(arg[x], &flag);
		if (flag == 1 || check_list_num(node->num, stack) == 1)
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
	{
		write(2, "Error\n", 6);
		return (1);
	}
//	print_stack(stack_a);
	if (check_order(stack_a) == 0)
		return (0);
	else
	{
		if (argc == 3)
			two_nums(&stack_a);
		else if (argc == 4)
			three_nums(&stack_a);
		else if (argc > 4)
			sort_nums(&stack_a, &stack_b, argc);
	
//		indx_the_list(&stack_a);
//		res = dup_list(stack_a);
//		res = find_min(stack_a);
//		printf("%p, %d\n", res, res->num);
//		write(1, "stack A\n", 8);
//		stack_a = NULL;
//		res = find_median(stack_a, argc);
//		print_stack(stack_a);
//		write(1, "res:\n", 5);
///		print_stack(res);
//		write(1, "stack B\n", 8);
//		print_stack(stack_b);
	//	swap(&stack_a);
//		rotate(&stack_a);
	//	reverse_rotate(&stack_a);
//		push_to_b(&stack_a, &stack_b);
//		write(1, "--------\nstack A\n", 17);
//		print_stack(stack_a);
//		write(1, "stack B\n", 8);
//		print_stack(stack_b);
	
		free_list(stack_a);
		free_list(stack_b);
	}
	return (0);
}
