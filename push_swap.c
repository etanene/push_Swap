/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalmer- <afalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 20:02:29 by afalmer-          #+#    #+#             */
/*   Updated: 2019/04/18 18:50:32 by afalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ruby -e "puts (-20 .. 20).to_a.shuffle.join(' ')"

#include "push_swap.h"

// void	ft_sort(t_stack **main, t_stack **off, int pivot, int count);
// void	ft_revsort(t_stack **main, t_stack **off, int pivot, int count);

// void	ft_revsort(t_stack **main, t_stack **off, int pivot, int count)
// {
// 	int		mainsize;
// 	int		offsize;
// 	int		i;

// 	mainsize = 0;
// 	offsize = 0;
// 	ft_printf("REV_START\n");
// 	ft_printf("pivot: %d\n", pivot);
// 	ft_printf("count: %d\n", count);
// 	ft_print_ab(*main, *off);
// 	if (count < 2)
// 	{
// 		if (count == 1)
// 		{
// 			ft_push_op(main, off);
// 			ft_printf("pa\n");
// 			ft_print_ab(*main, *off);
// 		}
// 		return ;
// 	}
// 	i = 0;
// 	while (i++ < count)
// 	{
// 		if ((*main)->value > pivot)
// 		{
// 			ft_push_op(main, off);
// 			ft_printf("pa\n");
// 			ft_print_ab(*main, *off);
// 			offsize++;
// 		}
// 		else
// 		{
// 			ft_rotate_op(main);
// 			ft_printf("rb\n");
// 			ft_print_ab(*main, *off);
// 			mainsize++;
// 		}
// 	}
// 	ft_printf("main: %d, off: %d\n", mainsize, offsize);
// 	i = 0;
// 	// if (mainsize < offsize && (*main)->value != pivot)
// 	// {
// 		while (i++ < mainsize)
// 		{
// 			ft_revrotate_op(main);
// 			ft_printf("rrb\n");
// 			ft_print_ab(*main, *off);
// 		}
// 	// }
// 	// else if ((*main)->value != pivot)
// 	// {
// 	// 	while (i++ < offsize)
// 	// 	{
// 	// 		ft_rotate_op(main);
// 	// 		ft_printf("rb\n");
// 	// 		ft_print_ab(*main, *off);
// 	// 	}
// 	// }
// 	if (pivot == (*main)->value && mainsize != 1)
// 	{
// 		ft_swap_op(main);
// 		ft_printf("sb\n");
// 		ft_print_ab(*main, *off);
// 	}
// 	ft_sort(off, main, (*off)->value, offsize);
// 	ft_revsort(main, off, (*main)->value, mainsize);
// }

// void	ft_sort(t_stack **main, t_stack **off, int pivot, int count)
// {
// 	int		mainsize;
// 	int		offsize;
// 	int		i;

// 	mainsize = 0;
// 	offsize = 0;
// 	ft_printf("START\n");
// 	ft_printf("pivot: %d\n", pivot);
// 	ft_printf("count: %d\n", count);
// 	ft_print_ab(*main, *off);
// 	if (count < 2)
// 	{
// 		return ;
// 	}
// 	i = 0;
// 	while (i++ < count)
// 	{
// 		if ((*main)->value < pivot)
// 		{
// 			ft_push_op(main, off);
// 			ft_printf("pb\n");
// 			ft_print_ab(*main, *off);
// 			offsize++;
// 		}
// 		else
// 		{
// 			ft_rotate_op(main);
// 			ft_printf("ra\n");
// 			ft_print_ab(*main, *off);
// 			mainsize++;
// 		}
// 	}
// 	ft_printf("main: %d, off: %d\n", mainsize, offsize);
// 	i = 0;
// 	// if (mainsize < offsize && (*main)->value != pivot)
// 	// {
// 		while (i++ < mainsize)
// 		{
// 			ft_revrotate_op(main);
// 			ft_printf("rra\n");
// 			ft_print_ab(*main, *off);
// 		}
// 	// }
// 	// else if ((*main)->value != pivot)
// 	// {
// 	// 	while (i++ < offsize)
// 	// 	{
// 	// 		ft_rotate_op(main);
// 	// 		ft_printf("ra\n");
// 	// 		ft_print_ab(*main, *off);
// 	// 	}
// 	// }
// 	if (pivot == (*main)->value && mainsize != 1)
// 	{
// 		ft_swap_op(main);
// 		ft_printf("sa\n");
// 		ft_print_ab(*main, *off);
// 	}
// 	if (*main)
// 		ft_sort(main, off, (*main)->value, mainsize);
// 	if (*off)
// 		ft_revsort(off, main, (*off)->value, offsize);
// }

void	ft_sort(t_stack **a, t_stack **b, int size);
void	ft_revsort(t_stack **b, t_stack **a, int size);

void	ft_revsort(t_stack **b, t_stack **a, int size)
{
	int		bsize;
	int		asize;
	int		pivot;
	int		i;

	bsize = 0;
	asize = 0;
	pivot = (*b)->value;
	// ft_printf("REV_START\n");
	// ft_printf("pivot: %d\n", pivot);
	// ft_printf("size: %d\n", size);
	// ft_print_ab(*a, *b);
	if (size < 2)
	{
		if (size == 1)
		{
			ft_push_op(b, a);
			ft_printf("pa\n");
			// ft_print_ab(*a, *b);
		}
		return ;
	}
	i = 0;
	while (i++ < size)
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
	}
	i = 0;
	// ft_printf("asize: %d, bsize: %d\n", asize, bsize);
	if (pivot != (*b)->value)
	{
		while (i++ < bsize)
		{
			ft_revrotate_op(b);
			ft_printf("rrb\n");
			// ft_print_ab(*a, *b);
		}
	}
	if (pivot == (*b)->value && bsize != 1)
	{
		ft_swap_op(b);
		ft_printf("sb\n");
		// ft_print_ab(*a, *b);
	}
	ft_sort(a, b, asize);
	ft_revsort(b, a, bsize);
}

void	ft_sort(t_stack **a, t_stack **b, int size)
{
	int		asize;
	int		bsize;
	int		pivot;
	int		i;

	asize = 0;
	bsize = 0;
	pivot = (*a)->value;
	// ft_printf("START\n");
	// ft_printf("pivot: %d\n", pivot);
	// ft_printf("size: %d\n", size);
	// ft_print_ab(*a, *b);
	if (size < 2)
	{
		return ;
	}
	i = 0;
	while (i++ < size)
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
	}
	i = 0;
	// ft_printf("asize: %d, bsize: %d\n", asize, bsize);
	if (pivot != (*a)->value)
	{
		while (i++ < asize)
		{
			ft_revrotate_op(a);
			ft_printf("rra\n");
			// ft_print_ab(*a, *b);
		}
	}
	if (pivot == (*a)->value && asize != 1)
	{
		ft_swap_op(a);
		ft_printf("sa\n");
		// ft_print_ab(*a, *b);
	}
	ft_sort(a, b, asize);
	ft_revsort(b, a, bsize);
}

int		main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	b = NULL;
	if (ac == 1)
		return (0);
	if ((a = ft_set_stack(++av, ac - 1)) == NULL)
	{
		ft_printf("Error\n");
		return (0);
	}
	ft_print_ab(a, b);
	ft_sort(&a, &b, ac - 1);
	// ft_printf("END\n");
	// ft_print_ab(a, b);
	return (0);
}
