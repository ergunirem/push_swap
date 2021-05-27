/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rev_rotate.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: icikrikc <icikrikc@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/25 16:29:50 by icikrikc      #+#    #+#                 */
/*   Updated: 2021/05/27 12:32:15 by icikrikc      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	rev_rotate(t_stack **stack, int *check)
{
	t_stack	*tmp;
	t_stack	*first;

	//do I need protection? and check == operated?
	if (*stack && (*stack)->next)
	{
		tmp = (*stack);
		while (*stack && (*stack)->next && (*stack)->next->next)
				(*stack) = (*stack)->next;
		first = (*stack)->next;
		(*stack)->next = NULL;
		first->next = tmp;
		(*stack) = first;
		*check = OPERATED;
	}
}

void	rra(t_stack **stack_a)
{
	int	check;

	rev_rotate(stack_a, &check);
	if (check == OPERATED)
		write(1, "rra\n", 4);
}

void	rrb(t_stack **stack_b)
{
	int check;

	rev_rotate(stack_b, &check);
	if (check == OPERATED)
		write(1, "rrb\n", 4);
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	int check;

	rev_rotate(stack_a, &check);
	rev_rotate(stack_b, &check);
	write(1, "rrr\n", 4);

}
