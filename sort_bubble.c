/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bubble_sort.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: icikrikc <icikrikc@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/27 16:51:01 by icikrikc      #+#    #+#                 */
/*   Updated: 2021/06/19 09:56:42 by icikrikc      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bubble_sort(t_stack **stack_a, t_stack **stack_b, t_all *all)
{
	while(!is_sorted((*stack_a)))
	{
		while((*stack_a))
		{
			if ((*stack_a)->next && (*stack_a)->num > (*stack_a)->next->num)
				sa(stack_a);
			pb(stack_a, stack_b, all);
		}
		while((*stack_b))
		{
			if ((*stack_b)->next && (*stack_b)->num < (*stack_b)->next->num)
				sb(stack_b);
			pa(stack_a, stack_b, all);
		}
	}
}

