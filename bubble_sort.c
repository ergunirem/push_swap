/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bubble_sort.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: icikrikc <icikrikc@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/27 16:51:01 by icikrikc      #+#    #+#                 */
/*   Updated: 2021/05/28 21:37:01 by icikrikc      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bubble_sort(t_stack **stack_a, t_stack **stack_b)
{
	int i;

	// printf("Sorted:%d\n", is_sorted((*stack_a)));
	// i = 15;
	while(!is_sorted((*stack_a)))
	{
		// printf("Sorted:%d\n", is_sorted((*stack_a)));
		while((*stack_a))
		{
			if ((*stack_a)->next && (*stack_a)->num > (*stack_a)->next->num)
				sa(stack_a);
			pb(stack_a, stack_b);
		}
		// print_stacks((*stack_a), (*stack_b));
		while((*stack_b))
		{
			if ((*stack_b)->next && (*stack_b)->num < (*stack_b)->next->num)
				sb(stack_b);
			pa(stack_a, stack_b);
		}
		i--;
		// print_stacks((*stack_a), (*stack_b));
	}
	// printf("head:%d\n", (*stack_a)->num);
	// printf("LAST Sorted:%d\n", is_sorted((*stack_a)));
}

