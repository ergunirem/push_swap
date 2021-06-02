/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: icikrikc <icikrikc@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/22 12:36:57 by icikrikc      #+#    #+#                 */
/*   Updated: 2021/06/02 21:25:12 by icikrikc      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_doubles(t_list *stack_a)
{
	t_list	*current;
	t_list	*rest;

	current = stack_a;
	while (current)
	{
		// printf("current:%d\n", current->content);
		// printf("------\n");
		rest = current->next;
		while (rest)
		{
			// printf("rest:%d\n", rest->content);
			if (current->content == rest->content)
			{
				ft_lstfree(&stack_a);
				ft_exit_basic("Doubles in stack\n");
			}
			rest = rest->next;
		}
		current = current->next;
	}
}

t_stack	*parse_arguments(int argc, char **argv, t_all *all)
{
	int		i;
	int		num;
	t_stack	*new;
	t_stack	*stack_a = all->stack_a;

	all->size_a = argc - 1;
	all->size_b = 0;
	while (argc > 1)
	{
		// printf("%s\n", argv[argc - 1]);
		num = push_swap_atoi(argv[argc - 1]);
		if (num == -1)
		{
			ft_lstfree((t_list **)&stack_a);
			ft_exit_basic("");
		}
		new = ft_lst_new_node(num);
		if (!new)
		{
			ft_lstfree((t_list **)&stack_a);
			ft_exit_basic("");
		}
		llst_add_to_front(&stack_a, new);
		argc--;
	}
	// printf("SIZE: %d\n", ft_lstsize((t_list *)stack_a));
	check_doubles((t_list *)stack_a);
	// while (stack_a)
	// {
	// 	printf("%d\n", stack_a->num);
	// 	stack_a = stack_a->next;
	// }
	return(stack_a);
}

void	print_stacks(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;

	tmp_a = stack_a;
	tmp_b = stack_b;
	int	a = ft_lstsize((t_list *)stack_a);
	int	b = ft_lstsize((t_list *)stack_b);
	printf("%s", GREEN);
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
	printf("%s", NORMAL);
	printf("\n\n");

}

int	main(int argc, char **argv)
{
	t_all	all;

	//do I need them?
	all.stack_a = NULL;
	all.stack_b = NULL;
	all.a_head = all.stack_a;
	all.a_tail = all.stack_a;
	if (argc < 2)
		ft_exit_basic("No argument provided\n");
	all.stack_a = parse_arguments(argc, argv, &all);

	// /////////////////////////////////////////////
	// printf("%s\nBEFORE SORT%s\n", BLUE, NORMAL);
	// print_stacks(stack_a, stack_b);
	// //////////////////////////////////////////////

	//SORT
	// printf("OPERATIONS\n-----------.------\n");
	t_stack	*stack_a = all.stack_a;
	t_stack	*stack_b = all.stack_b;
	sort_stack(&stack_a, &stack_b, &all);
	// printf("\n\n");
	//////

	// if(is_sorted(stack_a))
	// {
	// 	// //////////////////////////////////////////////
	// 	printf("%sAFTER SORT%s\n", RED, NORMAL);
	// print_stacks(stack_a, stack_b);
	// 	// //////////////////////////////////////////////
	// }

	//reverse_print
	// t_stack *last = (t_stack *)ft_lstlast((t_list *)stack_a);
	// while (last)
	// {
	// 	printf("%d\n", last->num);
	// 	last = last->prev;
	// }

	//free stacks
	// ft_lstfree((t_list **)&stack_a);
	// ft_lstfree((t_list **)&stack_b);
	return (0);
}
