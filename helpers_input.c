/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input_check.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: icikrikc <icikrikc@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/22 16:33:08 by icikrikc      #+#    #+#                 */
/*   Updated: 2021/06/01 13:14:26 by icikrikc      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	int	skip_whitespace(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
			|| str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
			i++;
		else
			break ;
	}
	return (i);
}

static	void	sign_check(const char *str, int	*sign, int *i)
{
	if (str[*i] == '-')
	{
		*sign = -1;
		(*i)++;
	}
	else if (str[*i] == '+')
	{
		*sign = 1;
		(*i)++;
	}
}

int	push_swap_atoi(const char *str)
{
	int		i;
	long	res;
	int		sign;

	res = 0;
	sign = 1;
	i = skip_whitespace(str);
	sign_check(str, &sign, &i);
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]) == 0)
			return (-1);
		res = res * 10 + str[i] - '0';
		i++;
	}
	if (sign * res > 2147483647 || sign * res < -2147483648
		|| (sign == -1 && res == 0))
		return (-1);
	return (sign * res);
}
