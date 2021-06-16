/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   helper.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: icikrikc <icikrikc@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/25 13:39:42 by icikrikc      #+#    #+#                 */
/*   Updated: 2021/06/16 18:20:56 by icikrikc      ########   odam.nl         */
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
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

int	ft_lstmin_num(t_stack **stack)
{
	int		tmp_min;
	t_stack	*tmp;

	tmp = *stack;
	tmp_min = 0;
	if (tmp)
		tmp_min = tmp->num;
	while (tmp)
	{
		if (tmp->num < tmp_min)
			tmp_min = tmp->num;
		tmp = tmp->next;
	}
	return (tmp_min);
}

int	ft_lstmax_num(t_stack **stack)
{
	int		tmp_max;
	t_stack	*tmp;

	tmp = *stack;
	tmp_max = 0;
	if (tmp)
		tmp_max = tmp->num;
	while (tmp)
	{
		if (tmp->num > tmp_max)
			tmp_max = tmp->num;
		tmp = tmp->next;
	}
	return (tmp_max);
}
