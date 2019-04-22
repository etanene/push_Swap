/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalmer- <afalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 20:02:29 by afalmer-          #+#    #+#             */
/*   Updated: 2019/04/22 15:00:25 by afalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ruby -e "puts (-20 .. 20).to_a.shuffle.join(' ')"

#include "push_swap.h"

void	ft_sort(t_stack **a, t_stack **b, int size);
void	ft_revsort(t_stack **b, t_stack **a, int size);

int		*ft_set_arr(t_stack *stack, int size)
{
	int		*res;
	int		i;

	res = (int*)malloc(sizeof(int) * size);
	i = 0;
	while (i < size)
	{
		res[i] = stack->value;
		stack = stack->next;
		i++;
	}
	return (res);
}

int		ft_partition(int *arr, int left, int right)
{
	int		pivot;
	int		temp;

	pivot = arr[(left + right) / 2];
	while (left < right)
	{
		while (arr[left] < pivot)
			left++;
		while (arr[right] > pivot)
			right--;
		if (left == right)
			break ;
		temp = arr[left];
		arr[left] = arr[right];
		arr[right] = temp;
	}
	return (left);
}

int		ft_quickselect_median(int *arr, int left, int right, int ind)
{
	int		pivot;

	pivot = ft_partition(arr, left, right);
	if (pivot == ind)
		return (arr[pivot]);
	else if (pivot < ind)
		return (ft_quickselect_median(arr, left, pivot - 1, ind));
	else
		return (ft_quickselect_median(arr, pivot + 1, right, ind));
}

int		ft_get_median(t_stack *stack, int size)
{
	int		*arr;
	int		median;

	arr = ft_set_arr(stack, size);
	median = ft_quickselect_median(arr, 0, size - 1, size / 2);
	free(arr);
	return (median);
}

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
	ft_printf("START\n");
	ft_printf("pivot: %d\n", pivot);
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
	ft_printf("END\n");
	ft_print_ab(a, b);
	return (0);
}
