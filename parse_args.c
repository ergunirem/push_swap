/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_args.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: icikrikc <icikrikc@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/06/16 23:24:37 by icikrikc      #+#    #+#                 */
/*   Updated: 2021/06/17 09:02:10 by icikrikc      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	check_doubles(t_list *stack_a)
{
	t_list	*current;
	t_list	*rest;

	current = stack_a;
	while (current)
	{
		rest = current->next;
		while (rest)
		{
			if (current->content == rest->content)
			{
				ft_lstfree(&stack_a);
				ft_exit_basic("");
			}
			rest = rest->next;
		}
		current = current->next;
	}
}

t_stack	*parse_arguments(int argc, char **argv, t_all *all)
{
	int		num;
	t_stack	*new;
	t_stack	*stack_a;

	stack_a = all->stack_a;
	while (argc > 1)
	{
		num = push_swap_atoi(argv[argc - 1]);
		new = ft_lst_new_node(num);
		if (!new)
		{
			ft_lstfree((t_list **)&stack_a);
			ft_exit_basic("");
		}
		llst_add_to_front(&stack_a, new);
		argc--;
	}
	check_doubles((t_list *)stack_a);
	return (stack_a);
}
