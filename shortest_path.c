/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   shortest_path.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: icikrikc <icikrikc@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/02 13:27:09 by icikrikc      #+#    #+#                 */
/*   Updated: 2021/06/02 20:32:11 by icikrikc      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	// printf("step:%d\n", step);
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
