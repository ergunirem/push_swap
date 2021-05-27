/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: icikrikc <icikrikc@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/25 11:37:39 by icikrikc      #+#    #+#                 */
/*   Updated: 2021/05/27 16:59:27 by icikrikc      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	sort_stack(t_stack **stack_a, t_stack **stack_b)
{
	int	size;

	size = ft_lstsize((t_list *)(*stack_a));
	if (size == 2 && (*stack_a)->num > (*stack_a)->next->num)
		ra(stack_a);
	else
		bubble_sort(stack_a, stack_b);
		// simple_sort(stack_a, stack_b);
}


