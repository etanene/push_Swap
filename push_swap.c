/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleksandr <aleksandr@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/13 20:02:29 by afalmer-          #+#    #+#             */
/*   Updated: 2019/04/22 21:26:57 by aleksandr        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ruby -e "puts (-20 .. 20).to_a.shuffle.join(' ')"

#include "push_swap.h"

void	ft_sort(t_stack **a, t_stack **b, int size);
void	ft_revsort(t_stack **b, t_stack **a, int size);

int		ft_is_sort_size(t_stack *stack, int size, int direct)
{
	while (stack->next)
	{
		if (direct == ASC && stack->value > stack->next->value)
			return (0);
		else if (direct == DESC && stack->value < stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	ft_sort3(t_stack **stack, int size, int direct)
{
	int		max;
	int		min;

	if (!*stack || ft_is_sort_size(*stack, size, direct))
		return ;
	max = (*stack)->value;
	min = max;
	while ((*stack)->next)
	{
		
	}
}

void	ft_revsort(t_stack **b, t_stack **a, int size)
{
	int		bsize;
	int		asize;
	int		pivot;
	int		i;

	bsize = 0;
	asize = 0;
	pivot = ft_get_median(*b, size);
	ft_printf("REV_START\n");
	ft_printf("pivot: %d\n", pivot);
	// ft_printf("size: %d\n", size);
	ft_print_ab(*a, *b);
	if (size < 2)
	{
		if (size == 1)
		{
			ft_push_op(b, a);
			ft_printf("pa\n");
			// ft_print_ab(*a, *b);
		}
		return ;
	}
	i = 0;
	while (i++ < size)
	{
		if ((*b)->value > pivot)
		{
			ft_push_op(b, a);
			asize++;
			ft_printf("pa\n");
			// ft_print_ab(*a, *b);
		}
		else
		{
			ft_rotate_op(b);
			bsize++;
			ft_printf("rb\n");
			// ft_print_ab(*a, *b);
		}
	}
	i = 0;
	ft_printf("asize: %d, bsize: %d\n", asize, bsize);
	if (pivot != (*b)->value)
	{
		while (i++ < bsize)
		{
			ft_revrotate_op(b);
			ft_printf("rrb\n");
			// ft_print_ab(*a, *b);
		}
	}
	ft_print_ab(*a, *b);
	ft_sort(a, b, asize);
	ft_revsort(b, a, bsize);
}

void	ft_sort(t_stack **a, t_stack **b, int size)
{
	int		asize;
	int		bsize;
	int		pivot;
	int		i;

	asize = 0;
	bsize = 0;
	pivot = ft_get_median(*a, size);
	ft_printf("START\n");
	ft_printf("pivot: %d\n", pivot);
	// ft_printf("size: %d\n", size);
	ft_print_ab(*a, *b);
	if (size < 2)
	{
		return ;
	}
	i = 0;
	while (i++ < size)
	{
		if ((*a)->value < pivot)
		{
			ft_push_op(a, b);
			bsize++;
			ft_printf("pb\n");
			// ft_print_ab(*a, *b);
		}
		else
		{
			ft_rotate_op(a);
			asize++;
			ft_printf("ra\n");
			// ft_print_ab(*a, *b);
		}
	}
	i = 0;
	ft_printf("asize: %d, bsize: %d\n", asize, bsize);
	if (pivot != (*a)->value)
	{
		while (i++ < asize)
		{
			ft_revrotate_op(a);
			ft_printf("rra\n");
			// ft_print_ab(*a, *b);
		}
	}
	ft_print_ab(*a, *b);
	ft_sort(a, b, asize);
	ft_revsort(b, a, bsize);
}

int		main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	b = NULL;
	if (ac == 1)
		return (0);
	if ((a = ft_set_stack(++av, ac - 1)) == NULL)
	{
		ft_printf("Error\n");
		return (0);
	}
	ft_print_ab(a, b);
	ft_sort(&a, &b, ac - 1);
	ft_printf("END\n");
	ft_print_ab(a, b);
	return (0);
}
