/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalmer- <afalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 14:38:21 by afalmer-          #+#    #+#             */
/*   Updated: 2019/04/27 14:40:01 by afalmer-         ###   ########.fr       */
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

void	ft_sort3_local(t_stack **stack, int size)
{
	int		max;
	int		min;

	min = ft_get_min(*stack);
	max = ft_get_max(*stack);
	while (!ft_is_sort_size(*stack, size, ASC))
	{
		if ((*stack)->value == max)
		{
			ft_rotate_op(stack);
			ft_printf("ra\n");
		}
		else if ((*stack)->next->value == max)
		{
			ft_revrotate_op(stack);
			ft_printf("rra\n");
		}
		else if ((*stack)->value != min && (*stack)->value != max)
		{
			ft_swap_op(stack);
			ft_printf("sa\n");
		}
	}
}

void	ft_revsort3(t_stack **b, t_stack **a, int bsize)
{
	int		asize;

	asize = 0;
	while (bsize > 0)
	{
		if (asize == 2 && (*a)->value > (*a)->next->value)
		{
			ft_swap_op(a);
			ft_printf("sa\n");
			// ft_print_ab(*a, *b);
		}
		if (bsize > 1 && (*b)->value < (*b)->next->value)
		{
			ft_swap_op(b);
			ft_printf("sb\n");
			// ft_print_ab(*a, *b);
		}
		else
		{
			ft_push_op(b, a);
			ft_printf("pa\n");
			// ft_print_ab(*a, *b);
			bsize--;
			asize++;
		}
	}
}

void	ft_sort3(t_stack **a, t_stack **b, int size)
{
	int		offsize;

	offsize = 0;
	while (!ft_is_sort_size(*a, size, ASC) || offsize)
	{
		if ((*a)->value > (*a)->next->value)
		{
			ft_swap_op(a);
			ft_printf("sa\n");
			// ft_print_ab(*a, *b);
		}
		else if (offsize)
		{
			ft_push_op(b, a);
			ft_printf("pa\n");
			// ft_print_ab(*a, *b);
			offsize--;
			size++;
		}
		else
		{
			ft_push_op(a, b);
			ft_printf("pb\n");
			// ft_print_ab(*a, *b);
			offsize++;
			size--;
		}
	}
}
