/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <martalop@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 19:37:54 by martalop          #+#    #+#             */
/*   Updated: 2024/04/18 20:53:00 by martalop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	print_stack(t_list **stack)
{
	while (*stack)
	{
		printf("list mem adress: [%p]\n  node[%p]: \n | num: %d\n | index: %d\n | cost: %d\n | target: %p\n | next: %p\n", stack, *stack, (*stack)->num, (*stack)->index, (*stack)->cost, (*stack)->target, (*stack)->next);
		*stack = (*stack)->next;
	}
	printf("\n");
}
