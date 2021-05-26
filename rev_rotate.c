/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rev_rotate.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: icikrikc <icikrikc@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/25 16:29:50 by icikrikc      #+#    #+#                 */
/*   Updated: 2021/05/26 11:29:02 by icikrikc      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	rev_rotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*first;

	//do I need protection?
	//like this: if (*stack && (*stack)->next)
	tmp = (*stack);
	while (*stack && (*stack)->next && (*stack)->next->next)
			(*stack) = (*stack)->next;
	first = (*stack)->next;
	(*stack)->next = NULL;
	first->next = tmp;
	(*stack) = first;
}

void	rra(t_stack **stack_a)
{
	write(1, "rra\n", 3);
	rev_rotate(stack_a);
}

void	rrb(t_stack **stack_b)
{
	write(1, "rrb\n", 3);
	rev_rotate(stack_b);
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	write(1, "rrr\n", 3);
	rev_rotate(stack_a);
	rev_rotate(stack_b);
}
