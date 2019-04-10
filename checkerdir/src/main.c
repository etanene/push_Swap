/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalmer- <afalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 19:19:19 by afalmer-          #+#    #+#             */
/*   Updated: 2019/04/10 20:25:43 by afalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		ft_check_input(char **av)
{
	while (*av)
	{
		if (ft_atoi(*av))
		av++;
	}
}

int		main(int ac, char **av)
{
	if (!ft_check_input(av))
	{
		ft_putstr("Error\n");
	}
	return (0);
}