/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <martalop@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 21:46:17 by martalop          #+#    #+#             */
/*   Updated: 2024/04/11 23:18:20 by martalop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h> 

void	swap(t_list **dir_stack, char let)
{
	t_list	*head;
	
	if (!(*dir_stack) || (*dir_stack)->next == NULL)
		return ;
	head = *dir_stack;
	*dir_stack = head->next;
	head->next = (*dir_stack)->next;
	(*dir_stack)->next = head;
	if (let == 'A')
		write(1, "sa\n", 3);
	if (let == 'B')
		write(1, "sb\n", 3);
	if (let == 'D')
		write(1, "ss\n", 3);
}

void	push_to_a(t_list **dir_stack_a, t_list **dir_stack_b)
{
	t_list	*tmp_b;

	if ((*dir_stack_b) == NULL)
		return ;
	tmp_b = *dir_stack_b;
	*dir_stack_b = (*dir_stack_b)->next;
	tmp_b->next = *dir_stack_a;
	*dir_stack_a = tmp_b;
	write(1, "pa\n", 3);
}

void	push_to_b(t_list **dir_stack_a, t_list **dir_stack_b)
{
	t_list	*tmp_a;

	if ((*dir_stack_a) == NULL)
		return ;
	tmp_a = *dir_stack_a;
	*dir_stack_a = (*dir_stack_a)->next; // muevo el puntero al segundo elemento de stack A
	tmp_a->next = *dir_stack_b; // en el next del primer nodo del stack A pongo la direccion del stack B
	*dir_stack_b = tmp_a; // el puntero stack B apunta al que antes era el primer nodo de stack A, ya actualizad
	
	// si el stack A esta vacio me daria segmentation fault en tmp_a->next si no tuviera el if
	// si el B esta vacio  quiero seguir anadiendo el nodo del a al b
	write(1, "pb\n", 3);
}

void	rotate(t_list **stack, char let)
{
	t_list	*aux;

	if (!*stack || !(*stack)->next)
		return ;
	aux = *stack;
	while (aux->next)
	{
		aux = aux->next;
	}
	aux->next = *stack;
	*stack = (*stack)->next;
	aux->next->next = NULL;
	if (let == 'A')
		write(1, "ra\n", 3);
	if (let == 'B')
		write(1, "rb\n", 3);
	if (let == 'D')
		write(1, "rr\n", 3);
}

void	reverse_rotate(t_list **stack, char let)
{
	t_list	*old_last;
	t_list	*aux;

	aux = *stack;
	if (!aux->next)
		return ;
	while (aux->next->next)
	{
		aux = aux->next;
	}
	old_last = aux->next;
	aux->next->next = *stack;
	*stack = old_last;
	aux->next = NULL;
	if (let == 'A')
		write(1, "rra\n", 4);
	if (let == 'B')
		write(1, "rrb\n", 4);
	if (let == 'D')
		write(1, "rrr\n", 4);
}
