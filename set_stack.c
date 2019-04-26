/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalmer- <afalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 14:07:36 by afalmer-          #+#    #+#             */
/*   Updated: 2019/04/26 13:14:39 by afalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_stack_size(t_stack *stack)
{
	int		size;

	size = 0;
	while (stack)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}

static t_stack	*ft_add_num(char *str, t_stack **stack)
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

static int		ft_arrlen(char **arr)
{
	int		count;

	count = 0;
	while (*arr++)
		count++;
	return (count);
}

t_stack			*ft_set_stack(char **av, int ac)
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
