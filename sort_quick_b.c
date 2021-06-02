/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_quick_b.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: icikrikc <icikrikc@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/02 15:10:54 by icikrikc      #+#    #+#                 */
/*   Updated: 2021/06/02 16:55:54 by icikrikc      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// static int find_higher(t_stack **left, int *pivot)
// {
// 	while (DATA(*left) ^ *pivot)
// 	{
// 		if (DATA(*left) > *pivot)
// 			return (1);
// 		*left = (*left)->prev;
// 	}
// 	return (0);
// }

// void ft_stack_b_routine(t_all *all, t_stack **stack_a, t_stack **stack_b, t_stack **left, int *size, int *pivot)
// {
// 	*size = ft_elem_between_pivot() + 1;
// 	if (*size < 30)
// 		ft_quick_select(size, &DATA(TOP_B));
// 	else
// 	{
// 		rb(stack_b);
// 		while (*stack_b != *left)
// 			(*stack_b > *pivot) ? pa(stack_a, stack_b, all) : rb(stack_b);
// 		pa(stack_a, stack_b, all);
// 		shortest_path(all, stack_a, 'a', (*stack_a)->next->num);
// 		shortest_path(all, stack_b, 'b', (*stack_b)->next->num);
// 		if ((*stack_a)->num > (*stack_a)->next->num)
// 			sa(stack_a);
// 		pa(stack_a, stack_b, all);
// 	}
// }

void	quick_sort_b(t_stack **stack_a, t_stack **stack_b, t_all *all)
{
	t_stack	*left;
	int		pivot;
	int		size;

	// while(all->size_b)
	// {
	// 	if(is_rev_sorted(*stack_b))
	// 		return ;
	// 	pivot = (*stack_b)->num;
	// 	if ((*stack_b)->sorted)
	// 		pa(stack_a, stack_b, all);
	// 	else
	// 	{
	// 		(*stack_b)->sorted = 1;
	// 		left = (*stack_b); //?left = HEAD_B.prev;
	// 		if(find_higher(&left, &pivot))
	// 			stack_b_routine(all, stack_a, stack_b, &left, &size, &pivot);
	// 		else
	// 			pa(stack_a, stack_b, all);
	// 	}
	// }
}
