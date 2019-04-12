/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalmer- <afalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 17:54:35 by afalmer-          #+#    #+#             */
/*   Updated: 2019/04/12 19:50:03 by afalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_print_stack(t_stack *stack, char name)
{
	if (name)
		ft_printf("%c |", name);
	if (stack)
	{
		ft_print_stack(stack->next, 0);
		ft_printf(" %d", stack->value);
	}
	if (name)
		ft_putchar('\n');
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
	elem->next = *stack;
	*stack = elem;
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
