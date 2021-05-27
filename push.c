/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: icikrikc <icikrikc@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/26 11:45:14 by icikrikc      #+#    #+#                 */
/*   Updated: 2021/05/26 20:05:15 by icikrikc      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	push(t_stack **stack1, t_stack **stack2, int *check)
{
	t_stack	*tmp;

	if (*stack2)
	{
		*check = OPERATED;
		tmp = (*stack2)->next;
		(*stack2)->next = *stack1;
		*stack1 = *stack2;
		*stack2 = tmp;
	}
}

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	int	check;

	push(stack_a, stack_b, &check);
	if (check == OPERATED)
		write(1, "pa\n", 3);

}

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	int	check;

	push(stack_b, stack_a, &check);
	if (check == OPERATED)
		write(1, "pb\n", 3);
}
