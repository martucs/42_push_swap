/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <martalop@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 19:29:45 by martalop          #+#    #+#             */
/*   Updated: 2024/04/11 22:35:46 by martalop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		if (lst->next != NULL)
		{
			lst = lst->next;
			i++;
		}
		else
		{
			i++;
			break ;
		}
	}
	return (i);
}

void	indx_list(t_list *stack)
{
	t_list	*tmp;
	int		i;
	int		len;

	i = 0;
	tmp = stack;
	len = ft_lstsize(stack);
	while (tmp->next && i <= (len / 2))
	{
		tmp->index = i;
		tmp = tmp->next;
		i++;
	}
	while (tmp)
	{
		tmp->index = i - len;
		tmp= tmp->next;
		i++;
	}
} 

t_list	*dup_list(t_list *stack)
{
	t_list	*new;
	t_list	*tmp;

	new = create_empty_node();
	tmp = new;
	while (stack)
	{
		new->num = stack->num;
		new->next = stack->next;
		stack = stack->next;
		new = new->next;
	}
	return (tmp);
} // esta mal, tengo que crear cada nodo con malloc
