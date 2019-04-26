/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   qsort.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalmer- <afalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 15:04:16 by afalmer-          #+#    #+#             */
/*   Updated: 2019/04/26 17:10:16 by afalmer-         ###   ########.fr       */
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

void	ft_revqsort(t_stack **b, t_stack **a, int size)
{
	int		bsize;
	int		asize;
	int		pivot;
	int		i;
	int		is_rr;

	bsize = 0;
	asize = 0;
	pivot = ft_get_median(*b, size);
	is_rr = (size == ft_stack_size(*b) ? 0 : 1);
	// ft_printf("REV_START\n");
	// ft_printf("pivot: %d\n", pivot);
	// ft_printf("size: %d\n", size);
	// ft_print_ab(*a, *b);
	if (ft_is_sort_size(*b, size, DESC))
	{
		while (size--)
		{
			ft_push_op(b, a);
			ft_printf("pa\n");
			// ft_print_ab(*a, *b);
		}
		return ;
	}
	// if (size < 6)
	// {
	// 	ft_revsort_size(b, a, size);
	// 	return ;
	// }
	if (size < 4)
	{
		if (size == 3)
		{
			ft_revsort3(b, a, size);
			return ;
		}
		else if (size == 2 && (*b)->value < (*b)->next->value)
		{
			ft_swap_op(b);
			ft_printf("sb\n");
			// ft_print_ab(*a, *b);
		}
		while (size--)
		{
			ft_push_op(b, a);
			ft_printf("pa\n");
			// ft_print_ab(*a, *b);
		}
		// ft_printf("size: %d\n", size);
		// ft_print_ab(*a, *b);
		return ;
	}
	i = 0;
	while (!ft_check_stack(*b, pivot, size, DESC))
	{
		if ((*b)->value > pivot)
		{
			ft_push_op(b, a);
			asize++;
			ft_printf("pa\n");
			// ft_print_ab(*a, *b);
		}
		else
		{
			ft_rotate_op(b);
			bsize++;
			ft_printf("rb\n");
			// ft_print_ab(*a, *b);
		}
		size--;
	}
	i = 0;
	while (is_rr && i++ < bsize)
	{
		ft_revrotate_op(b);
		ft_printf("rrb\n");
		// ft_print_ab(*a, *b);
	}
	bsize += size;
	// ft_printf("asize: %d, bsize: %d\n", asize, bsize);
	// ft_print_ab(*a, *b);
	ft_qsort(a, b, asize);
	ft_revqsort(b, a, bsize);
}

void	ft_qsort(t_stack **a, t_stack **b, int size)
{
	int		asize;
	int		bsize;
	int		pivot;
	int		i;
	int		is_rr;

	asize = 0;
	bsize = 0;
	pivot = ft_get_median(*a, size);
	is_rr = (size == ft_stack_size(*a)) ? 0 : 1;
	// ft_printf("START\n");
	// ft_printf("pivot: %d\n", pivot);
	// ft_printf("size: %d\n", size);
	// ft_print_ab(*a, *b);
	if (ft_is_sort_size(*a, size, ASC))
		return ;
	if (size < 4)
	{
		if (size == 3)
		{
			ft_sort3(a, b, size);
		}
		else if (size == 2 && (*a)->value > (*a)->next->value)
		{
			ft_swap_op(a);
			ft_printf("sa\n");
			// ft_print_ab(*a, *b);
		}
		// ft_printf("size: %d\n", size);
		// ft_print_ab(*a, *b);
		return ;
	}
	i = 0;
	while (!ft_check_stack(*a, pivot, size, ASC))
	{
		if ((*a)->value < pivot)
		{
			ft_push_op(a, b);
			bsize++;
			ft_printf("pb\n");
			// ft_print_ab(*a, *b);
		}
		else
		{
			ft_rotate_op(a);
			asize++;
			ft_printf("ra\n");
			// ft_print_ab(*a, *b);
		}
		size--;
		// ft_printf("size: %d\n", size);
	}
	i = 0;
	while (is_rr && i++ < asize)
	{
		ft_revrotate_op(a);
		ft_printf("rra\n");
		// ft_print_ab(*a, *b);
	}
	asize += size;
	// ft_printf("asize: %d, bsize: %d\n", asize, bsize);
	// ft_print_ab(*a, *b);
	ft_qsort(a, b, asize);
	ft_revqsort(b, a, bsize);
}
