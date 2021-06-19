/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_stacks.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: icikrikc <icikrikc@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/19 09:46:25 by icikrikc      #+#    #+#                 */
/*   Updated: 2021/06/19 09:47:13 by icikrikc      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stacks(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;

	tmp_a = stack_a;
	tmp_b = stack_b;
	int	a = ft_lstsize((t_list *)stack_a);
	int	b = ft_lstsize((t_list *)stack_b);
	printf("-----------------\nSTACKS: NEW ORDER\n-----------------\n");
	printf("a               b\n");
	printf("-               -\n");
	while (a > 0 || b > 0)
	{
		if(tmp_a == NULL)
			printf(" ");
		if (a > 0 && tmp_a)
		{
			printf("%d", tmp_a->num);
			tmp_a = tmp_a->next;
			a--;
		}
		if (b > 0 && tmp_b)
		{
			printf("               %d", tmp_b->num);
			tmp_b = tmp_b->next;
			b--;
		}
		printf("\n");
	}
	printf("\n\n");
}
