/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   helper.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: icikrikc <icikrikc@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/25 13:39:42 by icikrikc      #+#    #+#                 */
/*   Updated: 2021/05/25 13:56:38 by icikrikc      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*lst_new_node(int num)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->num = num;
	new->next = NULL;
	return (new);
}
