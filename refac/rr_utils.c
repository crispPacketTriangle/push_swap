/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lworden <lworden@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 21:55:08 by lworden           #+#    #+#             */
/*   Updated: 2024/03/29 21:55:11 by lworden          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// rra (reverse rotate a): shift down all elements of stack a by 1
// The last element becomes the first one
void	rra(t_stack *ab, int n)
{
	int	temp;
	int	i;

	i = 0;
	if (ab->a_len > 1)
	{
		temp = ab->a[0];
		while (i < ab->a_len -1)
		{
			ab->a[i] = ab->a[i + 1];
			i++;
		}
		ab->a[ab->a_len - 1] = temp;
	}
	if (n)
		ft_printf("rra\n");
	ab->t_count++;
}

// rrb (reverse rotate b): Shift down all elements of stack b by 1
void	rrb(t_stack *ab, int n)
{
	int	temp;
	int	i;

	i = 0;
	if (ab->b_len > 1)
	{
		temp = ab->b[0];
		while (i < ab->b_len -1)
		{
			ab->b[i] = ab->b[i + 1];
			i++;
		}
		ab->b[ab->b_len - 1] = temp;
	}
	if (n)
		ft_printf("rrb\n");
	ab->t_count++;
}

// rrr : rra and rrb at the same time
void	rrr(t_stack *ab)
{
	rra(ab, 0);
	rrb(ab, 0);
	ft_printf("rrr\n");
	ab->t_count--;
}
