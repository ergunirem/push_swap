/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sorted.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: icikrikc <icikrikc@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/27 16:44:36 by icikrikc      #+#    #+#                 */
/*   Updated: 2021/05/27 17:30:09 by icikrikc      ########   odam.nl         */
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
		if (s->next->num < s->num)
			cut++;
		s = s->next;
	}
	if (head->num < s->num)
		cut++;
	return (cut > 1 ? 0 : 1);
}
