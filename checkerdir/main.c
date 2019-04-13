/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalmer- <afalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 19:19:19 by afalmer-          #+#    #+#             */
/*   Updated: 2019/04/13 19:53:56 by afalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		ft_is_sort(t_stack *stack)
{
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int		ft_check_dup(t_stack *stack, int num)
{
	while (stack)
	{
		if (stack->value == num)
			return (0);
		stack = stack->next;
	}
	return (1);
}

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

t_stack	*ft_add_num(char *str, t_stack **stack)
{
	t_stack	*elem;
	int		num;

	num = ft_atoi(str);
	if (!ft_check_num(num, str) || \
			!ft_check_dup(*stack, num) || \
			!(elem = ft_create_elem(num)))
		return (NULL);
	ft_push(stack, elem);
	return (elem);
}

int		ft_arrlen(char **arr)
{
	int		count;

	count = 0;
	while (*arr++)
		count++;
	return (count);
}

t_stack	*ft_set_stack(char **av, int ac)
{
	t_stack	*stack;
	int		count;
	char	**nums;

	stack = NULL;
	if (ac == 1)
	{
		nums = ft_strsplit(*av, ' ');
		count = ft_arrlen(nums);
		while (count--)
		{
			if (!ft_add_num(nums[count], &stack))
				return (NULL);
		}
	}
	else
	{
		while (ac--)
		{
			if (!ft_add_num(av[ac], &stack))
				return (NULL);
		}
	}
	return (stack);
}

int		ft_read_input(t_stack **a, t_stack **b)
{
	char	*op;

	while (get_next_line(0, &op) > 0)
	{
		if (!ft_strcmp(op, "pa"))
			ft_push_op(b, a);
		else if (!ft_strcmp(op, "pb"))
			ft_push_op(b, a);
		else if (!ft_strcmp(op, "sa"))
			ft_swap_op(a);
		else if (!ft_strcmp(op, "sb"))
			ft_swap_op(b);
		else if (!ft_strcmp(op, "ss"))
		{
			ft_swap_op(a);
			ft_swap_op(b);
		}
		else if (!ft_strcmp(op, "ra"))
			ft_rotate_op(a);
		else if (!ft_strcmp(op, "rb"))
			ft_rotate_op(b);
		else if (!ft_strcmp(op, "rr"))
		{
			ft_rotate_op(a);
			ft_rotate_op(b);
		}
		else if (!ft_strcmp(op, "rra"))
			ft_revrotate_op(a);
		else if (!ft_strcmp(op, "rrb"))
			ft_revrotate_op(b);
		else if (!ft_strcmp(op, "rrr"))
		{
			ft_revrotate_op(a);
			ft_revrotate_op(b);
		}
		else
		{
			ft_strdel(&op);
			return (0);
		}
		ft_strdel(&op);
		ft_print_stack(*a, 'a');
		ft_print_stack(*b, 'b');
	}
	return (1);
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
		ft_putstr("Error\n");
		return (0);
	}
	ft_print_stack(a, 'a');
	ft_print_stack(b, 'b');
	if (!ft_read_input(&a, &b))
	{
		ft_putstr("Error\n");
		return (0);
	}
	if (ft_is_sort(a))
		printf("OK\n");
	else
		printf("KO\n");
	return (0);
}
