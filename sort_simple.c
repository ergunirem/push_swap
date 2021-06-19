/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_simple.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: icikrikc <icikrikc@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/02 09:52:44 by icikrikc      #+#    #+#                 */
/*   Updated: 2021/06/19 09:54:36 by icikrikc      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		count_step(t_stack **stack, int ref);
void	shortest_path(t_all *all, t_stack **stack, char stack_name, int ref);

/*
** Finds minimums and pushes them one by one to Stack B until 3 numbers left in A.
** Numbers in Stack B are now reverse sorted.
** Employs three_sort, then push everything back to Stack A
*/

void	sort_simple(t_stack **stack_a, t_stack **stack_b, t_all *all)
{
	int	min;

	while (all->size_a > 3)
	{
		min = ft_lstmin_num(stack_a);
		shortest_path(all, stack_a, 'a', min);
		pb(stack_a, stack_b, all);
		if(is_sorted((*stack_a)))
			break ;
	}
	sort_three(stack_a, all);
	while(all->size_b)
		pa(stack_a, stack_b, all);
}

/*
** Counts steps to reach the reference from the top of a stack
*/

int	count_step(t_stack **stack, int ref)
{
	int	step;
	t_stack	*tmp;

	tmp = *stack;
	step = 0;
		while (tmp->num != ref)
	{
		tmp = tmp->next;
		step++;
	}
	return (step);
}

/*
** Finds the shortest way to get a node on top the stack.
** Depending on step size and its proximity to the list size,
** it goes through the stack and either rotates or reverse roates
** until reference node is on top of the stack
*/

void	shortest_path(t_all *all, t_stack **stack, char stack_name, int ref)
{
	int	step;

	step = count_step(stack, ref);
	if (stack_name == 'b')
	{
		if(step < (all->size_b >> 1))
			while((*stack)->num != ref)
				rb(stack, all);
		else
			while((*stack)->num != ref)
				rrb(stack, all);
	}
	else
	{
		if(step < (all->size_a >> 1))
			while((*stack)->num != ref)
				ra(stack, all);
		else
			while((*stack)->num != ref)
				rra(stack, all);
	}
}
