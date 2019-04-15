/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalmer- <afalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 14:00:33 by afalmer-          #+#    #+#             */
/*   Updated: 2019/04/15 15:03:10 by afalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_is_sort(t_stack *a, t_stack *b)
{
	if (!a || b)
		return (0);
	while (a->next)
	{
		if (a->value > a->next->value)
			return (0);
		a = a->next;
	}
	return (1);
}

int		ft_check_dup(t_stack *stack, int num)
{
	while (stack)
	{
		if (stack->value == num)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int		ft_check_num(int num, char *str)
{
	char	*numstr;

	numstr = ft_itoa(num);
	if (!ft_strcmp(str, numstr))
	{
		ft_strdel(&numstr);
		return (1);
	}
	ft_strdel(&numstr);
	return (0);
}
