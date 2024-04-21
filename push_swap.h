/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <martalop@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 19:47:48 by martalop          #+#    #+#             */
/*   Updated: 2024/04/18 23:00:23 by martalop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	int				num;
	int				index;
	int				cost;
	struct s_list	*target;
	struct s_list	*next;
}	t_list;

t_list	*arg_check(char **arg);
void	free_list(t_list *list);
void	add_node_to_list(t_list *node, t_list **dir_stack);
int		check_list_num(int num, t_list *stack);
t_list	*create_empty_node(void);
int		ft_atoi(char *str, int *flag);
void	swap(t_list **dir_stack, char let);
//void	print_stack(t_list **stack);
void	push_to_a(t_list **dir_stack_a, t_list **dir_stack_b);
void	push_to_b(t_list **dir_stack_a, t_list **dir_stack_b);
void	rotate(t_list **stack, char let);
void	reverse_rotate(t_list **stack, char let);
void	two_nums(t_list **stack);
void	three_nums(t_list **stack_a);
int		check_order(t_list *stack);
t_list	*find_min(t_list *stack, t_list *min_num);
//t_list	*dup_list(t_list *stack);
t_list	*find_median(t_list *stack, int argc);
int		ft_lstsize(t_list *lst);
void	sort_nums(t_list **stack_a, t_list **stack_b, int argc);
void	indx_list(t_list *stack);
void	do_best_move(t_list **stack_a, t_list **stack_b);
void	find_target(t_list *stack_a, t_list	*stack_b);
void	find_cost(t_list *stack_b);
t_list	*smallest_cost(t_list *stack);
void	sort_pos(t_list **stack_a, t_list **stack_b, t_list *best_move);
void	sort_neg(t_list **stack_a, t_list **stack_b, t_list *best_move);
void	sort_diff(t_list **stack_a, t_list **stack_b, t_list *best_move);

#endif
