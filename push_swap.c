/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalmer- <afalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 20:02:29 by afalmer-          #+#    #+#             */
/*   Updated: 2019/04/16 13:54:38 by afalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort(t_stack **main, t_stack **off, int count)
{
	t_stack	*pivot;

	pivot = *main;
	ft_printf("START sort\npivot: %d\n", pivot->value);
	ft_printf("rotate a\n");
	ft_print_ab(*main, *off);
	while (count--)
	{
		if ((*main)->value < pivot->value)
		{
			ft_push_op(main, off);
			ft_printf("push to b\n");
			ft_print_ab(*main, *off);
		}
		else
		{
			ft_rotate_op(main);
			ft_printf("rotate a\n");
			ft_print_ab(*main, *off);
		}
	}
	ft_printf("END sort\n");
	ft_print_ab(*main, *off);
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
	return (0);
}
