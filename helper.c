/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   helper.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: icikrikc <icikrikc@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/25 13:39:42 by icikrikc      #+#    #+#                 */
/*   Updated: 2021/06/02 17:05:36 by icikrikc      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Given a reference (pointer to pointer) to the head of a list
** and and a new node, inserts it on the front of the list.
** 1. Makes next of new node as the head and previous null.
** 2. Changes previous head node to new node.
** 3. Make the new as the head of the list.
*/

void	llst_add_to_front(t_stack **head, t_stack *new)
{
	new->next = (*head);
	new->prev = NULL;
	if ((*head) != NULL)
		(*head)->prev = new;
	(*head) = new;
}

t_stack	*ft_lst_new_node(int num)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->num = num;
	new->sorted = 0;
	new->next = NULL;
	new->prev = NULL;
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
