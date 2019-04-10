/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalmer- <afalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 20:06:26 by afalmer-          #+#    #+#             */
/*   Updated: 2019/04/10 20:20:57 by afalmer-         ###   ########.fr       */
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

#endif