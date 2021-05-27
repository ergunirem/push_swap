/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_simple.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: icikrikc <icikrikc@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/27 15:15:43 by icikrikc      #+#    #+#                 */
/*   Updated: 2021/05/27 15:57:11 by icikrikc      ########   odam.nl         */
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

int	sort_min(t_stack **stack_a, t_stack **stack_b, int prev_max)
{

	int		min;
	t_stack	*tmp_min;
	t_stack	*tmp;

	tmp = *stack_a;
	if((*stack_a))
	{
		tmp_min = (*stack_a);
		min = (*stack_a)->num;
		while (tmp && tmp->next)
		{
			if (tmp->next->num < min)
			{
				min = tmp->next->num;
				tmp_min = tmp->next;
			}
			tmp = tmp->next;
		}
	}

	while((*stack_a))
	{
		if((*stack_a)->num != tmp_min->num)
			pb(stack_a, stack_b);
		if(ft_lstsize((t_list *)(*stack_a)) == 1)
			break;
		else
			ra(stack_a);
			// (*stack_a) = (*stack_a)->next;
	}
	// *stack_a = tmp_min;
	// (*stack_a)->next = NULL;
	// print_stacks((*stack_a), (*stack_b));

	//push all in b to a, now bottom of a is the min!
	while((*stack_b))
	{
		if((*stack_b)->num != prev_max)
			pa(stack_a, stack_b);
		if(*(stack_b))
		{
			if((*stack_b)->num == prev_max)
				break ;
		}
	}
	rra(stack_a);
	pb(stack_a, stack_b);
	return (min);
}

void	simple_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	prev_max;

	prev_max = 0;
	while((*stack_a))
	{
		prev_max = sort_min(stack_a, stack_b, prev_max);
		// print_stacks((*stack_a), (*stack_b));
	}
	while((*stack_b))
		pa(stack_a, stack_b);
}
