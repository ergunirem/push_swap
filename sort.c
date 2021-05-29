/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: icikrikc <icikrikc@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/25 11:37:39 by icikrikc      #+#    #+#                 */
/*   Updated: 2021/05/29 19:59:15 by icikrikc      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **stack_a)
{
	int	max;

	max = ft_lstmax(stack_a)->num;
	while(!is_sorted((*stack_a)))
	{
		if ((*stack_a)->num == max)
			ra(stack_a);
		else
			sa(stack_a);
	}
}

void		sort_four(t_stack **stack_a, t_stack **stack_b)
{
	int	min;

	min = ft_lstmin(stack_a)->num;
	while ((*stack_a)->num != min)
	{
		ra(stack_a);
	}
	pb(stack_a, stack_b);
	sort_three(stack_a);
	pa(stack_a, stack_b);
}

void	sort_five(t_stack **stack_a, t_stack **stack_b)
{
}

void	sort_stack(t_stack **stack_a, t_stack **stack_b)
{
	int	size;

	size = ft_lstsize((t_list *)(*stack_a));
	if (size == 2 && (*stack_a)->num < (*stack_a)->next->num)
		return ;
	else if (size == 2 && (*stack_a)->num > (*stack_a)->next->num)
		ra(stack_a);
	else if (size == 3)
		sort_three(stack_a);
	else if (size == 4)
		sort_four(stack_a, stack_b);
	else if (size == 5)
		sort_five(stack_a, stack_b);
	// else
	// 	bubble_sort(stack_a, stack_b);
	else
		simple_sort(stack_a, stack_b);
	// print_stacks((*stack_a), (*stack_b));
}


