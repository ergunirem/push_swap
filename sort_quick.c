/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_quick.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: icikrikc <icikrikc@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/31 15:51:59 by icikrikc      #+#    #+#                 */
/*   Updated: 2021/06/03 23:25:40 by icikrikc      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	quick_sort(t_stack **stack_a, t_stack **stack_b, t_all *all)
{
	// printf("-LIST-\n");
	// print_stacks((*stack_a), (*stack_b));
	while(!is_sorted((*stack_a)))
	{
		// printf("in2\n");
		// print_stacks((*stack_a), (*stack_b));
		// printf("-A-QUICK-\n");
		quick_sort_a(stack_a, stack_b, all);
		// printf("-After A-QUICK-\n");
		// print_stacks((*stack_a), (*stack_b));
		if (is_sorted((*stack_a)) && (!all->size_b || is_rev_sorted((*stack_b))))
		{
			// printf("-break-sorted\n");
			break ;
		}
		//bunu anlamadim ozellikle referans ne anlamadim
		shortest_path(all, stack_a, 'a', (*stack_a)->num);
		// printf("-After shortest path-\n");
		// print_stacks((*stack_a), (*stack_b));
		// printf("-B-QUICK-\n");
		quick_sort_b(stack_a, stack_b, all);
		// printf("-After B-QUICK-\n");
		// print_stacks((*stack_a), (*stack_b));
		// i--;
	}
	while(all->size_b)
		pa(stack_a, stack_b, all);
	// printf("-END-QUICK-\n");
	// print_stacks((*stack_a), (*stack_b));
}
