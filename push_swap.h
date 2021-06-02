/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: icikrikc <icikrikc@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/22 13:18:34 by icikrikc      #+#    #+#                 */
/*   Updated: 2021/06/02 20:30:45 by icikrikc      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "utils/libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h> //get rid of this because of printf?

# define GREEN "\033[38;5;2m"
# define NORMAL "\033[38;5;255m"
# define RED "\033[38;5;1m"
# define BLUE "\033[38;5;4m"
# define PURPLE "\033[0;35m"
# define YELLOW "\033[0;33m"

# define OPERATED 123
# define A_SIZE	0
# define B_SIZE 0

typedef struct		s_stack
{
	int				num;
	int				sorted;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

typedef	struct		s_all
{
	int			size_a;
	int			size_b;
	t_stack		*stack_a;
	t_stack		*a_head;
	t_stack		*a_tail;
	t_stack		*stack_b;
	t_stack		*b_head;
	t_stack		*b_tail;
}				t_all;

int		push_swap_atoi(const char *str);
void	sort_stack(t_stack **stack_a, t_stack **stack_b, t_all *all);

//operations
void	sa(t_stack **head_a);
void	sb(t_stack **head_b);
void	ss(t_stack **head_a, t_stack **head_b);
void	pa(t_stack **stack_a, t_stack **stack_b, t_all *all);
void	pb(t_stack **stack_a, t_stack **stack_b, t_all *all);
void	ra(t_stack **stack_a, t_all *all);
void	rb(t_stack **stack_b, t_all *all);
void	rr(t_stack **stack_a, t_stack **stack_b, t_all *all);
void	rra(t_stack **stack_a, t_all *all);
void	rrb(t_stack **stack_b, t_all *all);
void	rrr(t_stack **stack_a, t_stack **stack_b, t_all *all);

//lst funcs
void	llst_add_to_front(t_stack **head, t_stack *new);
t_stack	*ft_lst_new_node(int num);
t_stack	*ft_lstmax(t_stack **stack);
t_stack	*ft_lstmin(t_stack **stack);

//print
void	print_stacks(t_stack *stack_a, t_stack *stack_b);

//sorts
void	sort_three(t_stack **stack_a, t_all *all);
void	sort_four(t_stack **stack_a, t_stack **stack_b, t_all *all);
void	sort_five(t_stack **stack_a, t_stack **stack_b, t_all *all);
void	midi_sort(t_stack **stack_a, t_stack **stack_b, t_all *all);
void	quick_sort(t_stack **stack_a, t_stack **stack_b, t_all *all);
void	quick_sort_a(t_stack **stack_a, t_stack **stack_b, t_all *all);
void	quick_sort_b(t_stack **stack_a, t_stack **stack_b, t_all *all);
void	simple_sort(t_stack **stack_a, t_stack **stack_b);
void	bubble_sort(t_stack **stack_a, t_stack **stack_b);

//
void	shortest_path(t_all *all, t_stack **stack, char stack_name, int ref);
int		count_step(t_stack **stack, int ref);

int		is_sorted(t_stack *s);
int		is_rev_sorted(t_stack *s);
#endif
