/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   swap.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: icikrikc <icikrikc@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/26 11:32:41 by icikrikc      #+#    #+#                 */
/*   Updated: 2021/05/26 14:29:03 by icikrikc      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	swap(t_stack **stack, int *check)
{
	t_stack	*rest;
	t_stack	*first;
	t_stack	*second;
	int		size;

	size = ft_lstsize((t_list *)(*stack));
	if (size > 1)
	{
		*check = OPERATED;
		rest = (*stack)->next->next;
		first = (*stack);
		second = (*stack)->next;
		second->next = NULL;
		first->next = rest;
		second->next = first;
		(*stack) = second;
	}
	// tmp = (*stack)->next;
	// last = (t_stack *)ft_lstlast((t_list *)(*stack));
	// last->next = (*stack);
	// (*stack)->next = NULL;
	// (*stack) = tmp;

}

void	sa(t_stack **stack_a)
{
	int	check;

	swap(stack_a, &check);
	if (check == OPERATED)
		write(1, "sa\n", 3);
}

void	sb(t_stack **stack_b)
{
	int	check;

	swap(stack_b, &check);
	if (check == OPERATED)
		write(1, "sb\n", 3);

}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	write(1, "ss\n", 3);
	// swap(stack_a);
	// swap(stack_b);
}
