/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_quick_a.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: icikrikc <icikrikc@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/02 15:06:21 by icikrikc      #+#    #+#                 */
/*   Updated: 2021/06/02 20:29:12 by icikrikc      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	left_to_sort(t_stack **left, int *pivot)
{
	//DATA((*left)->next) ^ *pivot ???
	// while((*left)->next->num != *pivot)
	// {
	// 	if ((*left)->num < *pivot)
	// 		return(1);
	// 	*left = (*left)->next;
	// }
	// return (0);
	while ((*left))
	{
		if ((*left)->num < *pivot)
		{
			printf("lower:%d piv:%d\n", (*left)->num, *pivot);
			return (1);
		}

		*left = (*left)->next;
	}
	return (0);
}

void	push_lower_vals(t_all *all, t_stack **left, t_stack **stack_a, t_stack **stack_b, int *push, int *pivot)
{
	int		step;

	step = count_step(stack_a, (*left)->num);
	if (step < (all->size_a >> 1))
		while (*stack_a != *left)
			ra(stack_a, all);
	else
	{
		rra(stack_a, all);
		while (*stack_a != *left)
		{
			if ((*stack_a)->num < *pivot)
			{
				pb(stack_a, stack_b, all);
				++*push;
			}
			//segv?
			rra(stack_a, all);
		}
	}
	pb(stack_a, stack_b, all);
	++*push;
}

void	stack_a_routine(t_all *all, t_stack **stack_a, t_stack **stack_b, int *push, int *pivot)
{
	shortest_path(all, stack_a, 'a', *pivot);
	if (!(is_sorted(*stack_a) && (is_rev_sorted(*stack_b) || !all->size_b)))
		push = 0;
	if (all->size_a > 2)
		pb(stack_a, stack_b, all);
	printf("AFTER ROUTINE\n");
	print_stacks((*stack_a), (*stack_b));
}

void	quick_sort_a(t_stack **stack_a, t_stack **stack_b, t_all *all)
{
	t_stack	*left;
	int		pivot;
	int		push;

	push = 0;
	int i = 5;
	while(all->size_a > 1 && i > 0)
	{
		pivot = (*stack_a)->num;
		printf("PIV:%d\n", pivot);
		print_stacks((*stack_a), (*stack_b));
		(*stack_a)->sorted = 1;
		left = (*stack_a);
		if(left_to_sort(&left, &pivot))
		{
			push_lower_vals(all, &left, stack_a, stack_b, &push, &pivot);
			if(is_sorted((*stack_a)))
			{
				shortest_path(all, stack_a, 'a', (*stack_a)->num);
				break ;
			}
		}
		else
			stack_a_routine(all, stack_a, stack_b, &push, &pivot);
		// i--;
	}
}
