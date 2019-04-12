/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalmer- <afalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 18:36:02 by afalmer-          #+#    #+#             */
/*   Updated: 2019/04/12 19:48:29 by afalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_push_op(t_stack **a, t_stack **b, char name)
{
	t_stack	*elem;

	if (name == 'a')
	{
		if ((elem = ft_pop(b)))
			ft_push(a, elem);
	}
	else if (name == 'b')
	{
		if ((elem = ft_pop(a)))
			ft_push(b, elem);
	}
}
