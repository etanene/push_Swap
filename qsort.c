/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   qsort.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalmer- <afalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 15:04:16 by afalmer-          #+#    #+#             */
/*   Updated: 2019/04/27 15:57:44 by afalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_revqsort(t_stack **b, t_stack **a, int size, int print)
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
	if (ft_is_sort_size(*b, size, DESC))
	{
		while (size--)
		{
			ft_push_op(b, a, 'a', print);
		}
		return ;
	}
	if (size <= 3)
	{
		ft_revsort3(b, a, size, print);
		return ;
	}
	i = 0;
	while (!ft_check_stack(*b, pivot, size, DESC))
	{
		if ((*b)->value > pivot)
		{
			ft_push_op(b, a, 'a', print);
			asize++;
		}
		else
		{
			ft_rotate_op(b, a, 'b', print);
			bsize++;
		}
		size--;
	}
	i = 0;
	while (is_rr && i++ < bsize)
	{
		ft_revrotate_op(b, a, 'b', print);
	}
	bsize += size;
	ft_qsort(a, b, asize, print);
	ft_revqsort(b, a, bsize, print);
}

void	ft_qsort(t_stack **a, t_stack **b, int size, int print)
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
	if (ft_is_sort_size(*a, size, ASC))
		return ;
	if (size <= 3)
	{
		if (!is_rr)
		{
			ft_sort3_local(a, b, size, print);
		}
		else
		{
			ft_sort3(a, b, size, print);
		}
		return ;
	}
	i = 0;
	while (!ft_check_stack(*a, pivot, size, ASC))
	{
		if ((*a)->value < pivot)
		{
			ft_push_op(a, b, 'b', print);
			bsize++;
		}
		else
		{
			ft_rotate_op(a, b, 'a', print);
			asize++;
		}
		size--;
	}
	i = 0;
	while (is_rr && i++ < asize)
	{
		ft_revrotate_op(a, b, 'a', print);
	}
	asize += size;
	ft_qsort(a, b, asize, print);
	ft_revqsort(b, a, bsize, print);
}
