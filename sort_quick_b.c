/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_quick_b.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: icikrikc <icikrikc@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/02 15:10:54 by icikrikc      #+#    #+#                 */
/*   Updated: 2021/06/03 23:25:25 by icikrikc      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int find_higher(t_stack **left, int *pivot)
{
	//segf when (*left)->num ^ *pivot
	while (*left)
	{
		if ((*left)->num > *pivot)
			return (1);
		*left = (*left)->prev;
	}
	return (0);
}

static int	elem_between_pivot(t_all *all, t_stack **stack_a, t_stack **stack_b)
{
	int		count;
	t_stack	*it;
	// t_stack	*stack_a;
	// t_stack	*stack_b;

	// stack_a = all->stack_a;
	// stack_b = all->stack_b;
	count = 0;
	it = (*stack_b)->next;
	while (it != NULL)
	{
		if (it->sorted == 1)
		{
			//new addition > should I decrase count
			// count--;
			break ;
		}

		// if (it == stack_b)
		// 	break ;
		it = it->next;
		++count;
	}
	return (count);
}

/*
** Push element in decreasing order
**
** 1st parameter : list to be pushed
** 2nd paremeter : lenght of destination sublist
*/

void	push_max(t_all *all, t_stack **stack_a, t_stack **stack_b, t_stack **head, char name, const int len)
{
	int			ref;
	int			prev_ref;
	int			offset;
	t_stack		*tmp;

	// printf("in PUSHMAX\n");
	offset = 0;
	tmp = (*head);
	ref = tmp->num;
	prev_ref = ref;
	// printf("1)ref:%d\n", ref);
	while (offset < len)
	{
		if (tmp->num > ref)
			ref = tmp->num;
		++offset;
		tmp = tmp->next;
	}
	// printf("2)ref:%d\n", ref);
	shortest_path(all, head, name, ref);
	// printf("in pushmax - after shortest path\n");
	// print_stacks((*stack_a), (*stack_b));
	//DIFFERENT!
	if (name == 'b')
	{
		pa(stack_a, stack_b, all);
		//I added this to get back to skipped values between two pivots?
		if (prev_ref != ref)
			shortest_path(all, head, name, prev_ref);
		// printf("-PREV_REF > %d-\n", prev_ref);
		// print_stacks((*stack_a), (*stack_b));
	}
	else
		pb(stack_a, stack_b, all);
}

/*
** Quicksort sub-routine using select sort
**
** 1st parameter : number of elements between two pivots
** 2nd parameter : pivot value
*/

void	quick_select(t_all *all, t_stack **stack_a, t_stack **stack_b, int *pushed, int *pivot)
{
	// t_stack	*stack_a;
	// t_stack	*stack_b;

	// stack_a = all->stack_a;
	// stack_b = all->stack_b;
	while (*pushed)
	{
		push_max(all, stack_a, stack_b, stack_b, 'b', *pushed);
		// printf("PUSHED:%d SIZE:%d - PUSHMAX-AFTER\n", (*stack_a)->num, *pushed);
		// print_stacks((*stack_a), (*stack_b));
		(*pushed)--;
	}
	// printf("-PUSH LOOP-\n");
	// print_stacks((*stack_a), (*stack_b));
	if (is_sorted(*stack_a) && (is_rev_sorted(*stack_b) || !all->size_b))
	{
		// printf("-break-sorted\n");
		return ;
	}
	while ((*stack_a)->num < *pivot)
		pb(stack_a, stack_b, all);
	// printf("-After QUICK-SELECT-\n");
	// print_stacks((*stack_a), (*stack_b));
}

void stack_b_routine(t_all *all, t_stack **stack_a, t_stack **stack_b, t_stack **left, int *size, int *pivot)
{
	*size = elem_between_pivot(all, stack_a, stack_b) + 1;
	// printf("SIZE:%d\n", *size);
	if (*size < 30)
		quick_select(all, stack_a, stack_b, size, &((*stack_b)->num));
	else
	{
		rb(stack_b, all);
		while (*stack_b != *left)
			((*stack_b)->num > *pivot) ? pa(stack_a, stack_b, all) : rb(stack_b, all);
		pa(stack_a, stack_b, all);
		shortest_path(all, stack_a, 'a', (*stack_a)->next->num);
		shortest_path(all, stack_b, 'b', (*stack_b)->next->num);
		if ((*stack_a)->num > (*stack_a)->next->num)
			sa(stack_a);
		pa(stack_a, stack_b, all);
	}
}

void	quick_sort_b(t_stack **stack_a, t_stack **stack_b, t_all *all)
{
	t_stack	*left;
	int		pivot;
	int		size;

	while(all->size_b)
	{
		if(is_rev_sorted(*stack_b))
		{
			// printf("%sB REV sorted%s\n", RED, NORMAL);
			return ;
		}
		pivot = (*stack_b)->num;
		// printf("PIVB:%d\n", pivot);
		if ((*stack_b)->sorted)
		{
			// printf("already PIVOT > sorted:%d\n", (*stack_b)->sorted);
			pa(stack_a, stack_b, all);
		}
		else
		{
			(*stack_b)->sorted = 1;
			left = (t_stack *)ft_lstlast((t_list *)(*stack_b)); //?left = HEAD_B.prev; is this the last one?
			if(find_higher(&left, &pivot))
				stack_b_routine(all, stack_a, stack_b, &left, &size, &pivot);
			else
				pa(stack_a, stack_b, all);
		}
	}
}
