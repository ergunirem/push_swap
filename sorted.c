/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sorted.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: icikrikc <icikrikc@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/27 16:44:36 by icikrikc      #+#    #+#                 */
/*   Updated: 2021/06/02 09:32:05 by icikrikc      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		is_sorted(t_stack *s)
{
	t_stack	*head;
	int		cut;

	cut = 0;
	head = s;
	while (s && s->next)
	{
		if (s->num > s->next->num)
			return (0);
		s = s->next;
	}
	if (s->num < head->num)
		return (0);
	return (1);
}

int		is_rev_sorted(t_stack *s)
{
	t_stack	*head;
	int		cut;

	cut = 0;
	head = s;
	while (s && s->next)
	{
		if (s->num < s->next->num)
			return (0);
		s = s->next;
	}
	if (s->num > head->num)
		return (0);
	return (1);
}
