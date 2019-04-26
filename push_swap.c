/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalmer- <afalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 20:02:29 by afalmer-          #+#    #+#             */
/*   Updated: 2019/04/26 18:29:17 by afalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ruby -e "puts (-20 .. 20).to_a.shuffle.join(' ')"

#include "push_swap.h"

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

// void	ft_revsort_size(t_stack **b, t_stack **a, int bsize)
// {
// 	int		asize;
// 	int		swap;

// 	asize = 0;
// 	swap = 0;
// 	// ft_printf("size: %d\n", bsize);
// 	// ft_print_ab(*a, *b);
// 	while (bsize > 0)
// 	{
// 		if (!ft_is_sort_size(*a, asize, ASC))
// 		{
// 			if (!swap)
// 			{
// 				ft_swap_op(a);
// 				ft_printf("sa\n");
// 				// ft_print_ab(*a, *b);
// 				swap = 1;
// 			}
// 			else
// 			{
// 				ft_push_op(a, b);
// 				ft_printf("pb\n");
// 				// ft_print_ab(*a, *b);
// 				swap = 0;
// 				bsize++;
// 				asize--;
// 			}
// 		}
// 		else if (bsize > 1 && (*b)->value < (*b)->next->value)
// 		{
// 			ft_swap_op(b);
// 			ft_printf("sb\n");
// 			// ft_print_ab(*a, *b);
// 		}
// 		else
// 		{
// 			ft_push_op(b, a);
// 			ft_printf("pa\n");
// 			// ft_print_ab(*a, *b);
// 			asize++;
// 			bsize--;
// 		}
// 	}
// }

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

// int		*ft_get_shifts(t_stack *stack, int size)
// {
// 	int		*shifts;
// 	int		*arr;
// 	int		i;
// 	int		j;

// 	arr = ft_set_arr(stack, size);
// 	shifts = (int*)malloc(sizeof(int) * size);
// 	i = 0;
// 	while (i < size)
// 	{
// 		j = 0;
// 		while (j < size)
// 		{
// 			if (arr[i] == ft_quickselect(arr, 0, size - 1, j))
// 			{
// 				break ;
// 			}
// 			j++;
// 		}
// 		shifts[i] = i - j;
// 		i++;
// 	}
// 	return (shifts);
// }

// void	ft_sort_size(t_stack **stack, int size, int direct)
// {
// 	int		*shifts;
// 	int		i;
// 	int		max;

// 	shifts = ft_get_shifts(*stack, size);
// 	i = 0;
// 	while (i < size)
// 	{
		
// 	}
// }

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
	// ft_printf("START\n");
	// ft_print_ab(a, b);
	ac = (ac == 2) ? ft_stack_size(a) : ac - 1;
	// ft_revsort_size(&a, &b, ac);
	// ft_revqsort(&a, &b, ac);
	if (ac < 4)
	{
		ft_sort3(&a, &b, ac);
	}
	else
	{
		ft_qsort(&a, &b, ac);
	}
	// ft_printf("END\n");
	// ft_print_ab(a, b);
	return (0);
}
