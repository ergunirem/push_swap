/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_quick_a.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: icikrikc <icikrikc@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/02 15:06:21 by icikrikc      #+#    #+#                 */
/*   Updated: 2021/06/03 23:37:00 by icikrikc      ########   odam.nl         */
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
	//segf when > while((*left)->next->num ^ *pivot)
	while (*left)
	{
		if ((*left)->num < *pivot)
		{
			// printf("lower:%d piv:%d\n", (*left)->num, *pivot);
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
	// printf("push_lower\n");
	if (step < (all->size_a >> 1))
	{
		// ra(stack_a, all);
		while (*stack_a != *left)
		{
			// printf("ap:%p lp:%p\n", *stack_a, *left);
			// printf("left:%d\n", (*left)->num);
			// if ((*stack_a)->num < *pivot)
			// {
			// 	pb(stack_a, stack_b, all);
			// 	*left = *stack_a;
			// 	++*push;
			// }
			// printf("%sloop - all->size_a >> 1%s\n", RED, NORMAL);
			ra(stack_a, all);
			// *left = *stack_a;
			if(*stack_a == *left)
			{
				// printf("ap:%p lp:%p\n", *stack_a, *left);
				// printf("%sendofpushlower loop%s\n", YELLOW, NORMAL);
			}

		}
	}
	else
	{
		rra(stack_a, all);
		while (*stack_a != *left)
		{
			// printf("%sloop - else%s\n", RED, NORMAL);
			if ((*stack_a)->num < *pivot)
			{
				pb(stack_a, stack_b, all);
				++*push;
			}
			rra(stack_a, all);
		}
	}
	pb(stack_a, stack_b, all);
	++*push;
}

void	stack_a_routine(t_all *all, t_stack **stack_a, t_stack **stack_b, int *push, int *pivot)
{
	// printf("PIVOT-ROUTINE:%d\n", *pivot);
	shortest_path(all, stack_a, 'a', *pivot);
	if (!(is_sorted(*stack_a) && (is_rev_sorted(*stack_b) || !all->size_b)))
		push = 0; //degistirdim bunu ben onceden push = 0;
	if (all->size_a > 2)
		pb(stack_a, stack_b, all);
	// printf("AFTER ROUTINE\n");
	// print_stacks((*stack_a), (*stack_b));
}

void	quick_sort_a(t_stack **stack_a, t_stack **stack_b, t_all *all)
{
	t_stack	*left;
	int		pivot;
	int		push;

	push = 0;
	while(all->size_a > 1)
	{
		pivot = (*stack_a)->num;
		// printf("PIVA:%d\n", pivot);
		// print_stacks((*stack_a), (*stack_b));
		(*stack_a)->sorted = 1;
		left = (*stack_a);
		if(left_to_sort(&left, &pivot))
		{
			push_lower_vals(all, &left, stack_a, stack_b, &push, &pivot);
			//this does not exits in other
			//makes the pivot the head again because lower elements should be transferred!
			shortest_path(all, stack_a, 'a', pivot);
			if(is_sorted((*stack_a)))
			{
				// printf("A is SORTED in quick-sort-a after push lower vals\n");
				shortest_path(all, stack_a, 'a', (*stack_a)->num);
				break ;
			}
		}
		else
			stack_a_routine(all, stack_a, stack_b, &push, &pivot);
	}
}
