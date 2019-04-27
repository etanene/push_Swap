/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalmer- <afalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 14:03:29 by afalmer-          #+#    #+#             */
/*   Updated: 2019/04/27 20:00:48 by afalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

# define ASC 1
# define DESC -1

typedef struct		s_stack
{
	int				value;
	struct s_stack	*next;
}					t_stack;

int					ft_check_option(char *option);
int					ft_free_stack(t_stack *a, t_stack *b);

t_stack				*ft_set_stack(char **av, int ac);
int					ft_stack_size(t_stack *stack);
t_stack				*ft_create_elem(int num);

int					ft_check_num(int num, char *str);
int					ft_check_dup(t_stack *stack, int num);
int					ft_is_sort(t_stack *a, t_stack *b);
int					ft_is_sort_size(t_stack *stack, int size, int direct);
int					ft_check_stack(t_stack *stack, int pivot, int size, \
							int direct);

void				ft_print_stack(t_stack *stack);
void				ft_print_ab(t_stack *a, t_stack *b);
void				ft_push(t_stack **stack, t_stack *elem);
t_stack				*ft_pop(t_stack **stack);

void				ft_push_op(t_stack **from, t_stack **to, char op, \
							int print);
void				ft_swap_op(t_stack **main, t_stack **off, char op, \
							int print);
void				ft_rotate_op(t_stack **main, t_stack **off, char op, \
							int print);
void				ft_revrotate_op(t_stack **main, t_stack **off, char op, \
							int print);

void				ft_qsort(t_stack **a, t_stack **b, int size, int print);
void				ft_revqsort(t_stack **b, t_stack **a, int size, int print);
void				ft_sort3(t_stack **a, t_stack **b, int size, int print);
void				ft_revsort3(t_stack **a, t_stack **b, int size, int print);
void				ft_sortl(t_stack **a, t_stack **b, int size, int print);

int					ft_get_median(t_stack *stack, int size);

#endif
