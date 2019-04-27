/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   qsort.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalmer- <afalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 15:04:16 by afalmer-          #+#    #+#             */
/*   Updated: 2019/04/27 19:56:40 by afalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pusha_all(t_stack **b, t_stack **a, int print, int size)
{
	while (size--)
		ft_push_op(b, a, 'a', print);
}

void	ft_revqsort(t_stack **b, t_stack **a, int size, int print)
{
	int		bsize;
	int		asize;
	int		pivot;
	int		is_rr;

	bsize = 0;
	asize = 0;
	pivot = ft_get_median(*b, size);
	is_rr = (size == ft_stack_size(*b) ? 0 : 1);
	if (ft_is_sort_size(*b, size, DESC))
		return (ft_pusha_all(b, a, print, size));
	if (size <= 3)
		return (ft_revsort3(b, a, size, print));
	while (!ft_check_stack(*b, pivot, size, DESC) && size--)
	{
		if ((*b)->value > pivot && ++asize)
			ft_push_op(b, a, 'a', print);
		else if (++bsize)
			ft_rotate_op(b, a, 'b', print);
	}
	pivot = 0;
	while (is_rr && pivot++ < bsize)
		ft_revrotate_op(b, a, 'b', print);
	ft_qsort(a, b, asize, print);
	ft_revqsort(b, a, bsize + size, print);
}

void	ft_qsort(t_stack **a, t_stack **b, int size, int put)
{
	int		asize;
	int		bsize;
	int		pivot;
	int		rr;

	asize = 0;
	bsize = 0;
	pivot = ft_get_median(*a, size);
	rr = (size == ft_stack_size(*a)) ? 0 : 1;
	if (ft_is_sort_size(*a, size, ASC))
		return ;
	if (size <= 3)
		return (!rr ? ft_sortl(a, b, size, put) : ft_sort3(a, b, size, put));
	while (!ft_check_stack(*a, pivot, size, ASC) && size--)
	{
		if ((*a)->value < pivot && ++bsize)
			ft_push_op(a, b, 'b', put);
		else if (++asize)
			ft_rotate_op(a, b, 'a', put);
	}
	pivot = 0;
	while (rr && pivot++ < asize)
		ft_revrotate_op(a, b, 'a', put);
	ft_qsort(a, b, asize + size, put);
	ft_revqsort(b, a, bsize, put);
}
