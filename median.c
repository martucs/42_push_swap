/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <martalop@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 17:38:01 by martalop          #+#    #+#             */
/*   Updated: 2024/04/08 23:21:22 by martalop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*find_median(t_list *stack, int argc)
{
	int	median;
	int	count;
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
// si mi count es tres mi mediana es 0 (con: 7 4 -20 200 0 -3).
}
