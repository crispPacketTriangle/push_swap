/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data4_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lworden <lworden@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 21:53:01 by lworden           #+#    #+#             */
/*   Updated: 2024/03/29 21:53:03 by lworden          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	median(int *arr, int len)
{
	int	i;
	int	j;
	int	n;
	int	idx;

	i = 0;
	while (i < len)
	{
		j = 0;
		n = 0;
		while (j < len)
		{
			if (arr[j] < arr[i])
				n++;
			if (arr[j] > arr[i])
				n--;
			j++;
		}
		if (n == 1)
			idx = i;
		else if (n == 0)
			idx = i;
		i++;
	}
	return (arr[idx]);
}

int	max_idx(int *arr, int len)
{
	int	i;
	int	val;
	int	idx;

	i = 0;
	idx = 0;
	val = arr[i];
	while (i < len)
	{
		if (arr[i] > val)
		{
			val = arr[i];
			idx = i;
		}
		i++;
	}
	return (idx);
}

void	pop_max(t_stack *ab)
{
	int	i;
	int	val;

	i = 0;
	val = ab->b[i];
	while (i < ab->b_len)
	{
		if (ab->b[i] > val)
		{
			val = ab->b[i];
		}
		i++;
	}
	while (ab->b[ab->b_len - 1] != val)
	{
		rb(ab, 1);
	}
	pa(ab);
}

int	min(int *arr, int len)
{
	int	i;
	int	val;
	int	idx;

	i = 0;
	val = arr[i];
	while (i < len)
	{
		if (arr[i] < val)
		{
			val = arr[i];
		}
		i++;
	}
	return (val);
}

int	is_ord(int *arr, int len)
{
	int	i;

	i = 0;
	while (i < len - 1)
	{
		if (arr[i] < arr[i + 1])
			return (0);
		i++;
	}
	return (1);
}
