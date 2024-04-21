/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <martalop@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 17:38:01 by martalop          #+#    #+#             */
/*   Updated: 2024/04/16 11:05:35 by martalop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*find_median(t_list *stack, int argc)
{
	int		median;
	int		count;
	t_list	*min_num;

	median = (argc - 1) / 2;
	count = 1;
	min_num = NULL;
	while (count <= median)
	{
		min_num = find_min(stack, min_num);
		count++;
	}
	return (min_num);
}
