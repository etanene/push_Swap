/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalmer- <afalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 20:02:29 by afalmer-          #+#    #+#             */
/*   Updated: 2019/04/15 20:34:20 by afalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort(t_stack **main, t_stack **off, int count)
{
	t_stack	*pivot;
	int		count_main;
	int		count_off;

	if (count == 1)
		return ;
	pivot = *main;
	ft_printf("pivot: %d\n", pivot->value);
	ft_rotate_op(main);
	ft_printf("ra\n");
	ft_print_stack(*main, 'a');
	ft_print_stack(*off, 'b');
	count_main = count;
	count_off = 0;
	ft_printf("startcm: %d, co: %d\n", count_main - count_off, count_off);
	while (--count)
	{
		if ((*main)->value < pivot->value)
		{
			ft_push_op(main, off);
			ft_printf("pb\n");
			ft_print_stack(*main, 'a');
			ft_print_stack(*off, 'b');
			count_off++;
		}
		else
		{
			ft_rotate_op(main);
			ft_printf("ra\n");
			ft_print_stack(*main, 'a');
			ft_print_stack(*off, 'b');
		}
		ft_printf("c: %d\n", count);
	}
	ft_rotate_op(main);
	ft_printf("ra\n");
	ft_print_stack(*main, 'a');
	ft_print_stack(*off, 'b');
	ft_printf("endcm: %d, co: %d\n", count_main - count_off, count_off);
	ft_sort(main, off, count_main - count_off);
	ft_printf("count_main: %d\n", count_main);
	while (--count_main)
	{
		ft_push_op(off, main);
		ft_printf("pa\n");
		ft_print_stack(*main, 'a');
		ft_print_stack(*off, 'b');
	}
	ft_sort(off, main, count_off);
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
	ft_print_stack(a, 'a');
	ft_print_stack(b, 'b');
	ft_sort(&a, &b, ac - 1);
	return (0);
}
