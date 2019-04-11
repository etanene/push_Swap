/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalmer- <afalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 19:19:19 by afalmer-          #+#    #+#             */
/*   Updated: 2019/04/11 18:51:43 by afalmer-         ###   ########.fr       */
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
	int		num;

	a = NULL;
	while (ac--)
	{
		num = ft_atoi(av[ac]);
		if (!ft_check_num(num, av[ac]) || !ft_push(&a, num))
			return (NULL);
	}
}

int		main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	b = NULL;
	if (ac > 1)
	{
		if ((a = ft_set_stack(++av, ac - 1)) == NULL)
			ft_putstr("Error\n");
		else
			ft_print_stack(a, 'a');
	}
	return (0);
}