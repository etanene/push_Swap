/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalmer- <afalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 19:19:19 by afalmer-          #+#    #+#             */
/*   Updated: 2019/04/12 19:53:40 by afalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		ft_check_num(int num, char *str)
{
	char	*numstr;

	numstr = ft_itoa(num);
	if (!ft_strcmp(str, numstr))
	{
		ft_strdel(&numstr);
		return (1);
	}
	ft_strdel(&numstr);
	return (0);
}

t_stack	*ft_set_stack(char **av, int ac)
{
	t_stack	*a;
	t_stack *elem;
	int		num;

	a = NULL;
	while (ac--)
	{
		num = ft_atoi(av[ac]);
		if (!ft_check_num(num, av[ac]) || !(elem = ft_create_elem(num)))
			return (NULL);
		ft_push(&a, elem);
	}
	return (a);
}

int		main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	char	*op;

	b = NULL;
	if (ac > 1)
	{
		if ((a = ft_set_stack(++av, ac - 1)) == NULL)
		{
			ft_putstr("Error\n");
			return (0);
		}
		ft_print_stack(a, 'a');
		ft_print_stack(b, 'b');
		while (get_next_line(0, &op) > 0)
		{
			if (!ft_strcmp(op, "pa"))
				ft_push_op(&a, &b, 'a');
			else if (!ft_strcmp(op, "pb"))
				ft_push_op(&a, &b, 'b');
			else if (!ft_strcmp(op, "sa"))
				ft_swap_op();
			ft_print_stack(a, 'a');
			ft_print_stack(b, 'b');
		}
	}
	return (0);
}
