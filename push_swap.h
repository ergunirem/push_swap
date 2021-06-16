/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: icikrikc <icikrikc@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/22 13:18:34 by icikrikc      #+#    #+#                 */
/*   Updated: 2021/06/16 23:35:15 by icikrikc      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "utils/libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h> //get rid of this because of printf?

# define OPERATED 123

typedef struct s_stack
{
	int				num;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

typedef struct s_all
{
	int			size_a;
	int			size_b;
	t_stack		*stack_a;
	t_stack		*stack_b;
}				t_all;

/* operations */
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

/* lst funcs */
void	llst_add_to_front(t_stack **head, t_stack *new);
t_stack	*ft_lst_new_node(int num);
int		ft_lstmax_num(t_stack **stack);
int		ft_lstmin_num(t_stack **stack);

/* sorts */
void	sort_stack(t_stack **stack_a, t_stack **stack_b, t_all *all);
void	sort_three(t_stack **stack_a, t_all *all);
void	sort_four(t_stack **stack_a, t_stack **stack_b, t_all *all);
void	sort_five(t_stack **stack_a, t_stack **stack_b, t_all *all);
void	insertion_sort(t_stack **stack_a, t_stack **stack_b, t_all *all);

/* helpers */
t_stack	*parse_arguments(int argc, char **argv, t_all *all);
int		is_sorted(t_stack *s);
int		is_rev_sorted(t_stack *s);
int		stack_has(t_stack **stack, int chunk_max);
int		push_swap_atoi(const char *str);
#endif
