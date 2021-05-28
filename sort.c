/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: icikrikc <icikrikc@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/25 11:37:39 by icikrikc      #+#    #+#                 */
/*   Updated: 2021/05/28 21:33:13 by icikrikc      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **stack_a)
{
	int	max;

	max = ft_lstmax(stack_a)->num;
	while(!is_sorted((*stack_a)))
	{
		if ((*stack_a)->num == max)
			ra(stack_a);
		else
			sa(stack_a);
	}
}

void	sort_five(t_stack **stack_a, t_stack **stack_b)
{
	int	max;

	int	size;

	size = ft_lstsize((t_list *)(*stack_a));
	max = ft_lstmax(stack_a)->num;
	printf("size: %d\n", size);
	while((*stack_a))
	{
		// printf("i: %d\n", i);
		if(is_sorted((*stack_a)) && size == ft_lstsize((t_list *)(*stack_a)))
		{
			printf("break\n");
			break ;
		}
		if(ft_lstsize((t_list *)(*stack_a)) == 1)
			break ;
		else if ((*stack_a)->num == max && (*stack_a)->next)
			ra(stack_a);
		else if ((*stack_a)->num > (*stack_a)->next->num)
			sa(stack_a);
		else
			pb(stack_a, stack_b);
		// print_stacks((*stack_a), (*stack_b));
		// i--;
	}
	//print_stacks((*stack_a), (*stack_b));
	// printf("a > b\n");
	while ((*stack_b))
	{
		// else if ((*stack_a)->num == max && (*stack_a)->next)
		// 	ra(stack_a);
		if(ft_lstsize((t_list *)(*stack_a)) == 1)
			pa(stack_a, stack_b);
		else if ((*stack_a)->num < (*stack_a)->next->num)
		{
			sb(stack_b);
			pa(stack_a, stack_b);
		}
		else
			pa(stack_a, stack_b);
		// print_stacks((*stack_a), (*stack_b));
	}
}

void	sort_stack(t_stack **stack_a, t_stack **stack_b)
{
	int	size;

	size = ft_lstsize((t_list *)(*stack_a));
	if (size == 2 && (*stack_a)->num > (*stack_a)->next->num)
		ra(stack_a);
	else if (size == 3)
		sort_three(stack_a);
	else if (size <= 5)
		sort_five(stack_a, stack_b);
	// else
	// 	bubble_sort(stack_a, stack_b);
	else
		simple_sort(stack_a, stack_b);
	// print_stacks((*stack_a), (*stack_b));
}


