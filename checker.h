/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalmer- <afalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 20:06:26 by afalmer-          #+#    #+#             */
/*   Updated: 2019/04/12 19:48:35 by afalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

#include "libft.h"

typedef struct		s_stack
{
	int				value;
	struct s_stack	*next;
}					t_stack;

void				ft_print_stack(t_stack *stack, char name);
t_stack				*ft_create_elem(int num);
void				ft_push(t_stack **stack, t_stack *elem);
t_stack				*ft_pop(t_stack **stack);

void				ft_push_op(t_stack **a, t_stack **b, char name);

#endif