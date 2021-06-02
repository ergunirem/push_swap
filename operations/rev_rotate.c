/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rev_rev_rotate.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: icikrikc <icikrikc@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/25 16:29:50 by icikrikc      #+#    #+#                 */
/*   Updated: 2021/06/02 19:37:52 by icikrikc      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static	void	rev_rotate(t_stack **head)
{
	t_stack	*first;
	t_stack	*last;

	last = (t_stack *)ft_lstlast((t_list *)(*head));
	first = last;
	last->prev->next = NULL;
	last->next = NULL;
	first->prev = NULL;
	first->next = (*head);
	(*head) = first;
}

void	rra(t_stack **stack_a, t_all *all)
{
	if(all->size_a > 1)
	{
		rev_rotate(stack_a);
		write(1, "rra\n", 4);
	}
}

void	rrb(t_stack **stack_b, t_all *all)
{
	if(all->size_b > 1)
	{
		rev_rotate(stack_b);
		write(1, "rrb\n", 4);
	}
}

void	rrr(t_stack **stack_a, t_stack **stack_b, t_all *all)
{
	if(all->size_b > 1 && all->size_a > 1)
	{
		rev_rotate(stack_a);
		rev_rotate(stack_b);
		write(1, "rrr\n", 4);
	}
}
