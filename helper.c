/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   helper.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: icikrikc <icikrikc@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/25 13:39:42 by icikrikc      #+#    #+#                 */
/*   Updated: 2021/05/28 20:01:17 by icikrikc      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_lst_new_node(int num)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->num = num;
	new->next = NULL;
	return (new);
}

t_stack	*ft_lstmax(t_stack **stack)
{
	t_stack	*tmp_max;
	t_stack	*tmp;

	tmp = *stack;
	tmp_max = tmp;
	if(tmp)
	{
		while (tmp && tmp->next)
		{
			if (tmp->next->num > tmp_max->num)
				tmp_max = tmp->next;
			tmp = tmp->next;
		}
	}
	return (tmp_max);
}

t_stack	*ft_lstmin(t_stack **stack)
{
	t_stack	*tmp_min;
	t_stack	*tmp;

	tmp = *stack;
	tmp_min = tmp;
	if(tmp)
	{
		while (tmp && tmp->next)
		{
			if (tmp->next->num < tmp_min->num)
				tmp_min = tmp->next;
			tmp = tmp->next;
		}
	}
	return (tmp_min);
}
