/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_simple.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: icikrikc <icikrikc@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/27 15:15:43 by icikrikc      #+#    #+#                 */
/*   Updated: 2021/06/02 11:47:23 by icikrikc      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	Do this until A is empty
		find the min in stack_a
		move all elements from A to B except min
		now bottom of a is the min!
		move all elements from B to A as long as it's not the previous_max
		reverse rotate to put min on top of a and move it to b
	After A is empty, B will have stacks in descending order
	So, move move all elements from B to A which will give you the list in ascending order
*/

// int	sort_min(t_stack **stack_a, t_stack **stack_b, int prev_min)
// {

// 	int		min;

// 	min = ft_lstmin(stack_a)->num;
// 	while((*stack_a))
// 	{
// 		if((*stack_a)->num != min)
// 			pb(stack_a, stack_b);
// 		if(ft_lstsize((t_list *)(*stack_a)) == 1)
// 			break;
// 		else
// 			ra(stack_a);
// 	}

// 	//push all in b to a, now bottom of a is the min!
// 	while((*stack_b))
// 	{
// 		if((*stack_b)->num != prev_min)
// 			pa(stack_a, stack_b);
// 		if(*(stack_b))
// 		{
// 			if((*stack_b)->num == prev_min)
// 				break ;
// 		}
// 	}
// 	rra(stack_a);
// 	pb(stack_a, stack_b);
// 	return (min);
// }

// void	simple_sort(t_stack **stack_a, t_stack **stack_b)
// {
// 	int	prev_min;

// 	prev_min = 0;
// 	while((*stack_a))
// 	{
// 		prev_min = sort_min(stack_a, stack_b, prev_min);
// 		// print_stacks((*stack_a), (*stack_b));
// 	}
// 	while((*stack_b))
// 		pa(stack_a, stack_b);
// }
