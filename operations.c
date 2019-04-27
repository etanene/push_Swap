/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalmer- <afalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 18:36:02 by afalmer-          #+#    #+#             */
/*   Updated: 2019/04/27 19:59:12 by afalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_op(t_stack **from, t_stack **to, char op, int print)
{
	t_stack	*elem;

	if ((elem = ft_pop(from)))
		ft_push(to, elem);
	if (print >= 0)
		ft_printf("p%c\n", op);
	if ((print == 1 || print == -1) && op == 'a')
		ft_print_ab(*to, *from);
	else if ((print == 1 || print == -1) && op == 'b')
		ft_print_ab(*from, *to);
}

void	ft_swap_op(t_stack **main, t_stack **off, char op, int print)
{
	t_stack	*first;
	t_stack	*second;

	if ((first = ft_pop(main)))
	{
		if ((second = ft_pop(main)))
		{
			ft_push(main, first);
			ft_push(main, second);
		}
		else
			ft_push(main, first);
	}
	if (print >= 0)
		ft_printf("s%c\n", op);
	if ((print == 1 || print == -1) && op == 'a')
		ft_print_ab(*main, *off);
	else if ((print == 1 || print == -1) && op == 'b')
		ft_print_ab(*off, *main);
}

void	ft_rotate_op(t_stack **main, t_stack **off, char op, int print)
{
	t_stack	*end;

	if (*main && (*main)->next)
	{
		end = *main;
		while (end->next)
			end = end->next;
		end->next = *main;
		*main = (*main)->next;
		end->next->next = NULL;
	}
	if (print >= 0)
		ft_printf("r%c\n", op);
	if ((print == 1 || print == -1) && op == 'a')
		ft_print_ab(*main, *off);
	else if ((print == 1 || print == -1) && op == 'b')
		ft_print_ab(*off, *main);
}

void	ft_revrotate_op(t_stack **main, t_stack **off, char op, int print)
{
	t_stack	*end;

	if (*main && (*main)->next)
	{
		end = *main;
		while (end->next->next)
			end = end->next;
		end->next->next = *main;
		*main = end->next;
		end->next = NULL;
	}
	if (print >= 0)
		ft_printf("rr%c\n", op);
	if ((print == 1 || print == -1) && op == 'a')
		ft_print_ab(*main, *off);
	else if ((print == 1 || print == -1) && op == 'b')
		ft_print_ab(*off, *main);
}
