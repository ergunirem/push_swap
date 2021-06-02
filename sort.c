/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: icikrikc <icikrikc@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/25 11:37:39 by icikrikc      #+#    #+#                 */
/*   Updated: 2021/06/02 20:31:23 by icikrikc      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Calls a sort function based on the number of elements to sort
*/

void	sort_stack(t_stack **stack_a, t_stack **stack_b, t_all *all)
{
	if (all->size_a == 2 && (*stack_a)->num < (*stack_a)->next->num)
		return ;
	else if (all->size_a == 2 && (*stack_a)->num > (*stack_a)->next->num)
		sa(stack_a);
	else if (all->size_a == 3)
		sort_three(stack_a, all);
	else if (all->size_a == 4)
		sort_four(stack_a, stack_b, all);
	else if (all->size_a == 5)
		sort_five(stack_a, stack_b, all);
	else if (all->size_a < 20)
		midi_sort(stack_a, stack_b, all);
	else
		quick_sort(stack_a, stack_b, all);
}
