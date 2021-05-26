/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: icikrikc <icikrikc@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/22 13:18:34 by icikrikc      #+#    #+#                 */
/*   Updated: 2021/05/26 11:56:46 by icikrikc      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "utils/libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h> //get rid of this because of printf?

# define OPERATED 123

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

#endif
