/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalmer- <afalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 17:54:35 by afalmer-          #+#    #+#             */
/*   Updated: 2019/04/27 15:18:34 by afalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_ab(t_stack *a, t_stack *b)
{
	ft_printf("a |");
	ft_print_stack(a);
	ft_printf("\nb |");
	ft_print_stack(b);
	ft_printf("\n");
}

void	ft_print_stack(t_stack *stack)
{
	if (stack)
	{
		ft_print_stack(stack->next);
		ft_printf(" %d", stack->value);
	}
}

t_stack	*ft_create_elem(int num)
{
	t_stack	*elem;

	if ((elem = (t_stack*)malloc(sizeof(t_stack))) == NULL)
		return (NULL);
	elem->value = num;
	elem->next = NULL;
	return (elem);
}

void	ft_push(t_stack **stack, t_stack *elem)
{
	if (elem)
	{
		elem->next = *stack;
		*stack = elem;
	}
}

t_stack	*ft_pop(t_stack **stack)
{
	t_stack	*elem;

	if (!*stack)
		return (NULL);
	elem = *stack;
	*stack = (*stack)->next;
	elem->next = NULL;
	return (elem);
}
