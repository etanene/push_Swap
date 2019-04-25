/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalmer- <afalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 20:02:29 by afalmer-          #+#    #+#             */
/*   Updated: 2019/04/25 13:28:32 by afalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ruby -e "puts (-20 .. 20).to_a.shuffle.join(' ')"

#include "push_swap.h"

int		ft_is_sort_size(t_stack *stack, int size, int direct)
{
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

void	ft_sort3(t_stack **main, t_stack **off, int size, int direct)
{
	int		offsize;

	offsize = 0;
	while (!ft_is_sort_size(*main, size, direct) || offsize)
	{
		if ((direct == ASC && (*main)->value > (*main)->next->value) ||
			(direct == DESC && (*main)->value < (*main)->next->value))
		{
			ft_swap_op(main);
			ft_printf("sa\n");
			ft_print_ab(*main, *off);
		}
		else if (offsize)
		{
			ft_push_op(off, main);
			ft_printf("pa\n");
			ft_print_ab(*main, *off);
			offsize--;
			size++;
		}
		else
		{
			ft_push_op(main, off);
			ft_printf("pb\n");
			ft_print_ab(*main, *off);
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
	ft_printf("START\n");
	ft_print_ab(a, b);
	if (ac < 4)
	{
		ft_sort3(&a, &b, ac - 1, ASC);
	}
	else
	{
		ft_qsort(&a, &b, ac - 1);
	}
	ft_printf("END\n");
	ft_print_ab(a, b);
	return (0);
}
