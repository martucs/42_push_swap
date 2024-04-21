/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_signs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <martalop@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 22:49:50 by martalop          #+#    #+#             */
/*   Updated: 2024/04/18 22:59:18 by martalop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_pos(t_list **stack_a, t_list **stack_b, t_list *best_move)
{
	if (best_move->index > 0 && best_move->target->index > 0)
	{
		while (best_move != *stack_b && best_move->target != *stack_a)
		{
			rotate(stack_b, '0');
			rotate(stack_a, 'D');
		}
		while (best_move != *stack_b)
			rotate(stack_b, 'B');
		while (best_move->target != *stack_a)
			rotate(stack_a, 'A');
	}
}

void	sort_neg(t_list **stack_a, t_list **stack_b, t_list *best_move)
{
	if (best_move->index < 0 && best_move->target->index < 0)
	{
		while (best_move != *stack_b && best_move->target != *stack_a)
		{
			reverse_rotate(stack_b, '0');
			reverse_rotate(stack_a, 'D');
		}
		while (best_move != *stack_b)
			reverse_rotate(stack_b, 'B');
		while (best_move->target != *stack_a)
			reverse_rotate(stack_a, 'A');
	}
}

void	sort_diff(t_list **stack_a, t_list **stack_b, t_list *best_move)
{
	while (best_move != *stack_b)
	{
		if (best_move->index > 0)
			rotate(stack_b, 'B');
		else
			reverse_rotate(stack_b, 'B');
	}
	while (best_move->target != *stack_a)
	{
		if (best_move->target->index > 0)
			rotate(stack_a, 'A');
		else
			reverse_rotate(stack_a, 'A');
	}
}
