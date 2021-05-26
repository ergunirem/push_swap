/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rotate.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: icikrikc <icikrikc@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/25 12:26:12 by icikrikc      #+#    #+#                 */
/*   Updated: 2021/05/26 09:46:46 by icikrikc      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	rotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*last;

	//do I need protection?
	//like this: if (*stack && (*stack)->next)
	tmp = (*stack)->next;
	last = (t_stack *)ft_lstlast((t_list *)(*stack));
	last->next = (*stack);
	(*stack)->next = NULL;
	(*stack) = tmp;
// 	tmp = (*stack);
// 	while (tmp)
// 	{
// 		printf("%d\n", tmp->num);
// 		tmp = tmp->next;
// 	}
}

void	ra(t_stack **stack_a)
{
	write(1, "ra\n", 3);
	rotate(stack_a);
}

void	rb(t_stack **stack_b)
{
	write(1, "rb\n", 3);
	rotate(stack_b);
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	write(1, "rr\n", 3);
	rotate(stack_a);
	rotate(stack_b);
}
