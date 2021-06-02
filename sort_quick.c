/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_quick.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: icikrikc <icikrikc@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/31 15:51:59 by icikrikc      #+#    #+#                 */
/*   Updated: 2021/06/02 15:10:33 by icikrikc      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	quick_sort(t_stack **stack_a, t_stack **stack_b, t_all *all)
{
	int i = 5;

	print_stacks((*stack_a), (*stack_b));
	while(is_sorted((*stack_a)) || i > 0)
	{
		printf("----------------------------------\n");
		quick_sort_a(stack_a, stack_b, all);
		if (is_sorted((*stack_a)) && (!all->size_b || is_rev_sorted((*stack_b))))
			break ;
		//bunu anlamadim ozellikle referans ne anlamadim
		shortest_path(all, stack_a, 'a', (*stack_a)->next->num);
		// quick_sort_b();
		i--;
	}
	while(all->size_b)
		pa(stack_a, stack_b, all);
	print_stacks((*stack_a), (*stack_b));
}
