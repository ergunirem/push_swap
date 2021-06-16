/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_insertion.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: icikrikc <icikrikc@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/15 20:18:10 by icikrikc      #+#    #+#                 */
/*   Updated: 2021/06/16 18:08:50 by icikrikc      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Calculate if it's shorter to rotate or reverse rotate
** to get correct position of stack_b, and adjust accordingly.
*/

static void	shortest_rotation(t_stack **stack_b, t_all *all, int pos)
{
	int	i;

	i = -1;
	if (pos <= all->size_b / 2)
	{
		while (++i < pos)
			rb(stack_b, all);
	}
	else
	{
		while (++i < all->size_b - pos)
			rrb(stack_b, all);
	}
}

/*
** Move max of b to top to prevent any infinite loop
** while searching for correct position for the next element
*/

static void	move_max_to_top(t_stack **stack_b, t_all *all)
{
	int		pos;
	int		max;
	t_stack	*tmp;

	tmp = (*stack_b);
	max = ft_lstmax_num(stack_b);
	pos = 0;
	while (tmp)
	{
		if (tmp->num == max)
			break ;
		pos++;
		tmp = tmp->next;
	}
	shortest_rotation(stack_b, all, pos);
}

/*
** Check if number-to-be-pushed is smaller or bigger than others in stack_b.
** If it's in between, calculate the correct position to push in stack_b.
**
*/

static void	adjust_stack_b(t_stack **stack_a, t_stack **stack_b, t_all *all)
{
	t_stack	*tmp;
	int		pos;
	int		min_b;
	int		max_b;
	int		top_a;

	pos = 0;
	min_b = ft_lstmin_num(stack_b);
	max_b = ft_lstmax_num(stack_b);
	top_a = (*stack_a)->num;
	tmp = (*stack_b);
	if (top_a < min_b || top_a > max_b)
		return (move_max_to_top(stack_b, all));
	while (tmp)
	{
		pos++;
		if (tmp->next && (top_a < tmp->num && top_a > tmp->next->num))
			break ;
		tmp = tmp->next;
	}
	shortest_rotation(stack_b, all, pos);
}

/*
** Scan stack_a to check if it contains a number from the current chunk.
** If it has, adjust stack_b to the correct position to push current number.
** Else, rotate stack_a.
*/

static void	sort_each_chunk(t_stack **stack_a, t_stack **stack_b,
				t_all *all, int chunk_max)
{
	while ((stack_has(stack_a, chunk_max)))
	{
		if ((*stack_a)->num <= chunk_max)
		{
			adjust_stack_b(stack_a, stack_b, all);
			pb(stack_a, stack_b, all);
		}
		else
			ra(stack_a, all);
	}
	move_max_to_top(stack_b, all);
}

/*
** Divide stack_a to chunks based on number of elements.
** Sort each chunk in a loop. In the end, you'll have reverse sorted b.
** Move everything back to stack_a.
*/

void	insertion_sort(t_stack **stack_a, t_stack **stack_b, t_all *all)
{
	int	chunk;
	int	tmp;
	int	i;

	chunk = 0;
	i = 0;
	tmp = 5;
	if (all->size_a > 200)
		tmp = 11;
	chunk = (ft_lstmax_num(stack_a) - ft_lstmin_num(stack_a)) / tmp;
	while (++i < tmp)
		sort_each_chunk(stack_a, stack_b, all, chunk * i);
	sort_each_chunk(stack_a, stack_b, all, ft_lstmax_num(stack_a) + 1);
	while (all->size_b)
		pa(stack_a, stack_b, all);
}
