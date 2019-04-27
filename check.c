/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalmer- <afalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 14:00:33 by afalmer-          #+#    #+#             */
/*   Updated: 2019/04/27 14:57:12 by afalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_check_stack(t_stack *stack, int pivot, int size, int direct)
{
	while (size--)
	{
		if (direct == ASC && stack->value < pivot)
			return (0);
		else if (direct == DESC && stack->value > pivot)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int		ft_is_sort_size(t_stack *stack, int size, int direct)
{
	if (size == 0)
		return (1);
	while (--size)
	{
		if (direct == ASC && stack->value > stack->next->value)
			return (0);
		else if (direct == DESC && stack->value < stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

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
