/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data3_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lworden <lworden@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 21:50:59 by lworden           #+#    #+#             */
/*   Updated: 2024/03/29 21:51:15 by lworden          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_parll(t_stack *ab, t_opt *mv, int *a, int *b)
{
	if ((mv->aopt >= ab->a_len / 2) && (mv->bopt >= ab->b_len / 2))
		while (ab->a[ab->a_len -1] != *a && ab->b[ab->b_len - 1] != *b)
			rr(ab);
	else if ((mv->aopt < ab->a_len / 2) && (mv->bopt < ab->b_len / 2))
		while (ab->a[ab->a_len -1] != *a && ab->b[ab->b_len - 1] != *b)
			rrr(ab);
}

void	move_seq(t_stack *ab, t_opt *mv, int *a, int *b)
{
	while (ab->a[ab->a_len - 1] != *a)
	{
		if (mv->aopt >= ab->a_len / 2)
			ra(ab, 1);
		else
			rra(ab, 1);
	}
	while (ab->b[ab->b_len -1] != *b)
	{
		if (mv->bopt >= ab->b_len / 2)
			rb(ab, 1);
		else
			rrb(ab, 1);
	}
}

void	rotate(t_stack *ab)
{
	while (ab->a[ab->a_len - 1] != min(ab->a, ab->a_len))
	{
		if (max_idx(ab->a, ab->a_len) <= ab->a_len / 2)
			rra(ab, 1);
		else
			ra(ab, 1);
	}
}

void	order(t_stack *ab)
{
	int	med;
	int	seg;

	seg = ab->a_len / 2;
	med = median(ab->a, ab->a_len);
	while (ab->a_len > seg)
	{
		if (ab->a[ab->a_len - 1] <= med)
			pb(ab);
		else
		{
			ra(ab, 1);
		}
	}
}
