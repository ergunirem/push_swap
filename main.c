/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: icikrikc <icikrikc@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/22 12:36:57 by icikrikc      #+#    #+#                 */
/*   Updated: 2021/05/29 17:26:15 by icikrikc      ########   odam.nl         */
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

t_stack	*parse_arguments(int argc, char **argv, t_stack *stack_a)
{
	int		i;
	int		num;
	t_stack	*new;

	i = 1;
	while (i < argc)
	{
		// printf("%s\n", argv[i]);
		num = my_atoi(argv[i]);
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
		ft_lstadd_back((t_list **)&stack_a, (t_list *)new);
		i++;
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
	t_stack	*stack_a;
	t_stack	*stack_b;

	//do I need them?
	// stack_a = NULL;
	// stack_b = NULL;
	if (argc < 2)
		ft_exit_basic("No argument provided\n");
	stack_a = parse_arguments(argc, argv, stack_a);

	// /////////////////////////////////////////////
	// printf("%s\nBEFORE SORT%s\n", BLUE, NORMAL);
	// print_stacks(stack_a, stack_b);
	// //////////////////////////////////////////////

	//SORT
	// printf("OPERATIONS\n-----------------\n");
	sort_stack(&stack_a, &stack_b);
	// printf("\n\n");
	//////

	// if(is_sorted(stack_a))
	// {
	// 	// //////////////////////////////////////////////
	// 	printf("%sAFTER SORT%s\n", RED, NORMAL);
	// 	print_stacks(stack_a, stack_b);
	// 	// //////////////////////////////////////////////
	// }


	//free stacks
	ft_lstfree((t_list **)&stack_a);
	// ft_lstfree((t_list **)&stack_b);
	return (0);
}
