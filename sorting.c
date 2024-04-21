/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <martalop@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 21:22:09 by martalop          #+#    #+#             */
/*   Updated: 2024/04/21 14:24:25 by martalop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_cost(t_list *stack_b)
{
	if (stack_b->target->index == 0)
		return ;
	while (stack_b)
	{
		if (stack_b->index > 0 && stack_b->target->index > 0)
		{
			if (stack_b->index > stack_b->target->index)
				stack_b->cost = stack_b->index;
			else
				stack_b->cost = stack_b->target->index;
		}
		else if (stack_b->index < 0 && stack_b->target->index < 0)
		{
			if (stack_b->index < stack_b->target->index)
				stack_b->cost = stack_b->index;
			else
				stack_b->cost = stack_b->target->index;
		}
		else
			stack_b->cost = stack_b->index - stack_b->target->index;
		if (stack_b->cost < 0)
			stack_b->cost = stack_b->cost * -1;
		stack_b = stack_b->next;
	}
}

void	find_target(t_list *stack_a, t_list *stack_b)
{
	t_list	*pre_target;
	t_list	*target;

	while (stack_b)
	{
		pre_target = find_min(stack_a, stack_b);
		if (!pre_target)
			target = find_min(stack_a, NULL);
		else
			target = pre_target;
		stack_b->target = target;
		stack_b = stack_b->next;
	}
}

void	do_best_move(t_list **stack_a, t_list **stack_b)
{
	t_list	*best_move;
	int		i;

	i = 0;
	indx_list(*stack_a);
	indx_list(*stack_b);
	find_target(*stack_a, *stack_b);
	find_cost(*stack_b);
	best_move = smallest_cost(*stack_b);
	if (best_move->index > 0 && best_move->target->index > 0)
		sort_pos(stack_a, stack_b, best_move);
	else if (best_move->index < 0 && best_move->target->index < 0)
		sort_neg(stack_a, stack_b, best_move);
	else
		sort_diff(stack_a, stack_b, best_move);
	push_to_a(stack_a, stack_b);
}

void	sort_nums(t_list **stack_a, t_list **stack_b, int argc)
{
	t_list	*median;
	t_list	*last_target;
	int		i;

	i = 0;
	median = find_median(*stack_a, argc);
	while (ft_lstsize(*stack_a) > 3)
	{
		push_to_b(stack_a, stack_b);
		if ((*stack_b)->num > median->num)
			rotate(stack_b, 'B');
	}
	three_nums(stack_a);
	while (*stack_b != NULL)
		do_best_move(stack_a, stack_b);
	indx_list(*stack_a);
	last_target = find_min(*stack_a, NULL);
	while (last_target != *stack_a)
	{
		if (last_target->index < 0)
			reverse_rotate(stack_a, 'A');
		else
			rotate(stack_a, 'A');
	}
}
// I could also:
/*	if (last_target->index > 0)
	{
		while (i < last_target->index)
		{
			rotate(stack_a, 'A');
			i++;
		}
	}
	else if (last_target->index < 0)
	{
		while (i < (last_target->index * -1))
		{
			reverse_rotate(stack_a, 'A');
			i++;
		}
	}
*/
