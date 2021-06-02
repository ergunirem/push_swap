/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_midi.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: icikrikc <icikrikc@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/02 09:52:44 by icikrikc      #+#    #+#                 */
/*   Updated: 2021/06/02 20:31:48 by icikrikc      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Finds minimums and pushes them one by one to Stack B until 3 numbers left in A.
** Numbers in Stack B are now reverse sorted.
** Employs three_sort, then push everything back to Stack A
*/

void	midi_sort(t_stack **stack_a, t_stack **stack_b, t_all *all)
{
	// int	size;
	int	min;

	// size = all->size_a;
	// print_stacks((*stack_a), (*stack_b));
	while (all->size_a > 3) //size > 3
	{
		// printf("A:%d B:%d\n", all->size_a, all->size_b);
		min = ft_lstmin(stack_a)->num;
		// printf("min:%d\n", min);
		shortest_path(all, stack_a, 'a', min);
		pb(stack_a, stack_b, all);
		if(is_sorted((*stack_a)))
			break ;
		// size--;
	}
	sort_three(stack_a, all);
	while(all->size_b)
		pa(stack_a, stack_b, all);
	// print_stacks((*stack_a), (*stack_b));
}
