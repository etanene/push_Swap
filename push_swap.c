/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalmer- <afalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 20:02:29 by afalmer-          #+#    #+#             */
/*   Updated: 2019/04/27 16:06:21 by afalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ruby -e "puts (-20 .. 20).to_a.shuffle.join(' ')"

#include "push_swap.h"

int		main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	int		print;

	b = NULL;
	if (ac == 1)
		return (0);
	if ((print = ft_check_option(av[1])))
	{
		av++;
		ac--;
	}
	if ((a = ft_set_stack(++av, ac - 1)) == NULL)
	{
		ft_printf("Error\n");
		return (0);
	}
	ac = (ac == 2) ? ft_stack_size(a) : ac - 1;
	if (print)
	{
		ft_printf("START\n");
		ft_print_ab(a, b);
	}
	if (ac <= 3)
		ft_sort3_local(&a, &b, ac, print);
	else
		ft_qsort(&a, &b, ac, print);
	if (print)
	{
		ft_printf("END\n");
		ft_print_ab(a, b);
	}
	return (0);
}
