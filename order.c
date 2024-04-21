/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <martalop@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 12:08:05 by martalop          #+#    #+#             */
/*   Updated: 2024/04/18 21:10:55 by martalop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*smallest_cost(t_list *stack)
{
	t_list	*min;

	if (stack->cost == 0)
		return (stack);
	min = stack;
	while (stack)
	{
		if (stack->cost < min->cost)
			min = stack;
		stack = stack->next;
	}
	return (min);
}

void	two_nums(t_list **stack)
{
	if ((*stack)->num > (*stack)->next->num)
	{
		swap(stack, 'A');
	}
}

int	check_order(t_list *stack)
{
	while (stack->next)
	{
		if (stack->num < stack->next->num)
			stack = stack->next;
		else
			return (1);
	}
	return (0);
}

t_list	*find_min(t_list *stack, t_list *min_num)
{
	int		min;
	int		nb;
	t_list	*tmp;

	tmp = NULL;
	min = 2147483647;
	if (!min_num)
		nb = -2147483648;
	else
		nb = min_num->num;
	while (stack)
	{
		if (stack->num == -2147483648 && !min_num)
		{
			return (stack);
		}
		if (stack->num < min && stack->num > nb)
		{
			min = stack->num;
			tmp = stack;
		}
		stack = stack->next;
	}
	return (tmp);
}

void	three_nums(t_list **stack)
{
	if (!check_order(*stack))
		return ;
	if ((*stack)->num < (*stack)->next->num && \
			(*stack)->num < (*stack)->next->next->num)
	{
		swap(stack, 'A');
		rotate(stack, 'A');
	}
	else if ((*stack)->num > (*stack)->next->num && \
			(*stack)->num > (*stack)->next->next->num)
	{
		if ((*stack)->next->num > (*stack)->next->next->num)
		{
			rotate(stack, 'A');
			swap(stack, 'A');
		}
		else if ((*stack)->next->num < (*stack)->next->next->num)
			rotate(stack, 'A');
	}
	else if ((*stack)->num > (*stack)->next->num)
		swap(stack, 'A');
	else if ((*stack)->num < (*stack)->next->num)
		reverse_rotate(stack, 'A');
}
