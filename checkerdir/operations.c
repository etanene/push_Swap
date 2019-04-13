/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalmer- <afalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 18:36:02 by afalmer-          #+#    #+#             */
/*   Updated: 2019/04/13 16:08:08 by afalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_push_op(t_stack **from, t_stack **to)
{
	t_stack	*elem;

	if ((elem = ft_pop(from)))
		ft_push(to, elem);
}

void	ft_swap_op(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;

	if ((first = ft_pop(stack)))
	{
		if ((second = ft_pop(stack)))
		{
			ft_push(stack, first);
			ft_push(stack, second);
		}
		else
			ft_push(stack, first);
	}
}

void	ft_rotate_op(t_stack **stack)
{
	t_stack	*end;

	if (*stack && (*stack)->next)
	{
		end = *stack;
		while (end->next)
			end = end->next;
		end->next = *stack;
		*stack = (*stack)->next;
		end->next->next = NULL;
	}
}

void	ft_revrotate_op(t_stack **stack)
{
	t_stack	*end;

	if (*stack && (*stack)->next)
	{
		end = *stack;
		while(end->next->next)
			end = end->next;
		end->next->next = *stack;
		*stack = end->next;
		end->next = NULL;
	}
}
