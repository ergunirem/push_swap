/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: icikrikc <icikrikc@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/22 13:18:34 by icikrikc      #+#    #+#                 */
/*   Updated: 2021/05/27 16:51:42 by icikrikc      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "utils/libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h> //get rid of this because of printf?

# define OPERATED 123

# define GREEN "\033[38;5;2m"
# define NORMAL "\033[38;5;255m"
# define RED "\033[38;5;1m"
# define BLUE "\033[38;5;4m"
# define PURPLE "\033[0;35m"
# define YELLOW "\033[0;33m"

typedef struct		s_stack
{
	int				num;
	struct s_stack	*next;
}					t_stack;

int		my_atoi(const char *str);
void	sort_stack(t_stack **stack_a, t_stack **stack_b);

//operations
void	sa(t_stack **stack_a);
void	sb(t_stack **stack_b);
void	ss(t_stack **stack_a, t_stack **stack_b);
void	pa(t_stack **stack_a, t_stack **stack_b);
void	pb(t_stack **stack_a, t_stack **stack_b);
void	ra(t_stack **stack_a);
void	rb(t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);
void	rra(t_stack **stack_a);
void	rrb(t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);

//lst funcs
t_stack	*lst_new_node(int num);

//print
void	print_stacks(t_stack *stack_a, t_stack *stack_b);

//sorts
void	simple_sort(t_stack **stack_a, t_stack **stack_b);
void	bubble_sort(t_stack **stack_a, t_stack **stack_b);

int		is_sorted(t_stack *s);
#endif
