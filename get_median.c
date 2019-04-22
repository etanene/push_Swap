/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_median.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afalmer- <afalmer-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/22 18:24:01 by afalmer-          #+#    #+#             */
/*   Updated: 2019/04/22 18:24:35 by afalmer-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		*ft_set_arr(t_stack *stack, int size)
{
	int		*res;
	int		i;

	res = (int*)malloc(sizeof(int) * size);
	i = 0;
	while (i < size)
	{
		res[i] = stack->value;
		stack = stack->next;
		i++;
	}
	return (res);
}

int		ft_partition(int *arr, int left, int right)
{
	int		pivot;
	int		temp;

	pivot = arr[(left + right) / 2];
	while (left < right)
	{
		while (arr[left] < pivot)
			left++;
		while (arr[right] > pivot)
			right--;
		if (left == right)
			break ;
		temp = arr[left];
		arr[left] = arr[right];
		arr[right] = temp;
	}
	return (left);
}

int		ft_quickselect_median(int *arr, int left, int right, int ind)
{
	int		pivot;

	pivot = ft_partition(arr, left, right);
	if (pivot == ind)
		return (arr[pivot]);
	else if (pivot > ind)
		return (ft_quickselect_median(arr, left, pivot - 1, ind));
	else
		return (ft_quickselect_median(arr, pivot + 1, right, ind));
}

int		ft_get_median(t_stack *stack, int size)
{
	int		*arr;
	int		median;

	arr = ft_set_arr(stack, size);
	median = ft_quickselect_median(arr, 0, size - 1, size / 2);
	free(arr);
	return (median);
}
