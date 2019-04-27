/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalmer- <afalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 14:38:21 by afalmer-          #+#    #+#             */
/*   Updated: 2019/04/27 15:57:06 by afalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_get_min(t_stack *stack)
{
	int		min;

	min = stack->value;
	while (stack)
	{
		if (stack->value < min)
			min = stack->value;
		stack = stack->next;
	}
	return (min);
}

int		ft_get_max(t_stack *stack)
{
	int		max;

	max = stack->value;
	while (stack)
	{
		if (stack->value > max)
			max = stack->value;
		stack = stack->next;
	}
	return (max);
}

void	ft_sort3_local(t_stack **a, t_stack **b, int size, int print)
{
	int		max;
	int		min;

	min = ft_get_min(*a);
	max = ft_get_max(*a);
	while (!ft_is_sort_size(*a, size, ASC))
	{
		if ((*a)->value == max)
		{
			ft_rotate_op(a, b, 'a', print);
		}
		else if ((*a)->next->value == max)
		{
			ft_revrotate_op(a, b, 'a', print);
		}
		else if ((*a)->value != min && (*a)->value != max)
		{
			ft_swap_op(a, b, 'a', print);
		}
	}
}

void	ft_revsort3(t_stack **b, t_stack **a, int bsize, int print)
{
	int		asize;

	asize = 0;
	while (bsize > 0)
	{
		if (asize == 2 && (*a)->value > (*a)->next->value)
		{
			ft_swap_op(a, b, 'a', print);
		}
		if (bsize > 1 && (*b)->value < (*b)->next->value)
		{
			ft_swap_op(b, a, 'b', print);
		}
		else
		{
			ft_push_op(b, a, 'a', print);
			bsize--;
			asize++;
		}
	}
}

void	ft_sort3(t_stack **a, t_stack **b, int size, int print)
{
	int		offsize;

	offsize = 0;
	while (!ft_is_sort_size(*a, size, ASC) || offsize)
	{
		if ((*a)->value > (*a)->next->value)
		{
			ft_swap_op(a, b, 'a', print);
		}
		else if (offsize)
		{
			ft_push_op(b, a, 'a', print);
			offsize--;
			size++;
		}
		else
		{
			ft_push_op(a, b, 'b', print);
			offsize++;
			size--;
		}
	}
}
