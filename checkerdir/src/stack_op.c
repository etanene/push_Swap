/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalmer- <afalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 17:54:35 by afalmer-          #+#    #+#             */
/*   Updated: 2019/04/11 18:57:19 by afalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_print_stack(t_stack *stack, char name)
{
	if (name)
		ft_printf("%c |", name);
	if (!stack)
	{
		ft_putchar('\n');
		return ;
	}
	ft_print_stack(stack->next, 0);
	ft_printf(" %d", stack->value);
}

t_stack	*ft_push(t_stack **stack, int num)
{
	t_stack	*elem;

	if ((elem = (t_stack*)malloc(sizeof(t_stack))) == NULL)
		return (NULL);
	elem->value = num;
	elem->next = *stack;
	*stack = elem;
	return (*stack);
}