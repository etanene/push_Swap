/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shared.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalmer- <afalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 17:00:32 by afalmer-          #+#    #+#             */
/*   Updated: 2019/04/27 17:56:59 by afalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_check_option(char *option)
{
	if (ft_strnstr(option, "-v", 3))
		return (1);
	return (0);
}

int		ft_free_stack(t_stack *a, t_stack *b)
{
	t_stack	*temp;

	while (a)
	{
		temp = a->next;
		free(a);
		a = temp;
	}
	while (b)
	{
		temp = b->next;
		free(b);
		b = temp;
	}
	return (0);
}
