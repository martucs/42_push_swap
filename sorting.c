/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <martalop@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 21:22:09 by martalop          #+#    #+#             */
/*   Updated: 2024/04/12 15:28:44 by martalop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	find_cost(t_list *stack_b)
{
	if (stack_b->index + stack_b->target->index == 0)
		return ;
	while (stack_b)
	{
		if (stack_b->index > 0 && stack_b->target->index > 0) // mismo signo positivo
		{
			if (stack_b->index < stack_b->target->index)
				stack_b->cost = stack_b->target->index;
			else
				stack_b->cost = stack_b->index;
		}
		else if (stack_b->index < 0 && stack_b->target->index < 0) // mismo signo negativo
		{
			if (stack_b->index < stack_b->target->index)
				stack_b->cost = stack_b->index; // prq trabajamos con negativos
			else
				stack_b->cost = stack_b->target->index;
		}
		else // distintos signos
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
		pre_target = find_min(stack_a, stack_b); // busco mayor mas cercano
		if (!pre_target)
			target = find_min(stack_a, pre_target); // si no lo encuentro busco el min
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

	best_move = smallest_indx(*stack_b);
	if (best_move->index > 0 && best_move->target->index > 0) // si los dos son positivos
	{
		while (best_move != *stack_b && best_move->target != *stack_a) // mientras el best  move ni su target no esten al principio de la lista
		{
			rotate(stack_b, '0');
			rotate(stack_a, 'D');
		}
		while (best_move != *stack_b) // me ha ce los movimientos que le queden hacer individualmente (no a la vez) para el satck B
			rotate(stack_b, 'B');
		while (best_move->target != *stack_a)
			rotate(stack_a, 'A');
	}
	else if (best_move->index < 0 && best_move->target->index < 0) // si los dos negativos
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
	else // (best_move->index != best_move->target->index) // ---- > no puedo rotar o rev_rot a la vez en los dos stacks, rotan de manera independiente)
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
	/*if (best_move != *stack_b)
	{
		if (best_move->index > 0)
		{
			while (i < best_move->index)
			{
				rotate(stack_b, 'B');
				i++;
			}
		}
		else
		{
			while (i < (best_move->index * -1))
			{
				reverse_rotate(stack_b, 'B');
				i++;
			}
		}
	}
	if (best_move->target != *stack_a)
	{
		if (best_move->target->index > 0)
		{
			while (i < best_move->target->index)
			{
				rotate(stack_a, 'A');
				i++;
			}
		}
		else
		{
			while (i < (best_move->target->index * -1))
			{
				reverse_rotate(stack_a, 'A');
				i++;
			}
		}
	}*/
	push_to_a(stack_a, stack_b);
}

void	sort_nums(t_list **stack_a, t_list **stack_b, int argc)
{
	t_list	*median;
	t_list	*last_target;
	int		i;

	i = 0;
	median = find_median(*stack_a, argc);
//	printf("median = %d\n", median->num);
	while (ft_lstsize(*stack_a) > 3)
	{
		push_to_b(stack_a, stack_b);
		if ((*stack_b)->num > median->num)
			rotate(stack_b, 'B');
	}
	three_nums(stack_a);
	while (*stack_b != NULL) // tiene que ser while
	{
		do_best_move(stack_a, stack_b);
	}
	indx_list(*stack_a);
	last_target = find_min(*stack_a, NULL);
	if (last_target != *stack_a)
	{
		if (last_target->index > 0)
		{
			while (i < last_target->index)
			{
				rotate(stack_a, 'A');
				i++;
			}
		}
		else
		{
			while (i < (last_target->index * -1))
			{
				reverse_rotate(stack_a, 'A');
				i++;
			}
		}
	}
}
