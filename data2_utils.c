/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data2_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lworden <lworden@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 21:15:41 by lworden           #+#    #+#             */
/*   Updated: 2024/03/29 21:39:07 by lworden          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	opt_insert(t_stack *ab)
{
	int		i;
	int		j;
	t_opt	imal;
	t_opt	*mv;

	mv = &imal;
	mv->optscore = (ab->a_len / 2) + (ab->b_len / 2);
	i = 0;
	while (i < ab->b_len)
	{
		j = target(ab, i);
		score(ab, mv, i, 0);
		score(ab, mv, j, 1);
		update_score(ab, mv, i, j);
		i++;
	}
	move(ab, mv);
}

// largest a value smaller than b value	
int	target(t_stack *ab, int idx)
{
	int	i;
	int	trgt;
	int	trgt_idx;

	trgt_idx = max_idx(ab->a, ab->a_len); 
	trgt = ab->a[trgt_idx];
	i = 0;
	while (i < ab->a_len)
	{
		if (ab->a[i] < trgt && ab->a[i] > ab->b[idx])
		{
			trgt = ab->a[i];
			trgt_idx = i;
		}
		i++;
	}
	return (trgt_idx);
}

void	score(t_stack *ab, t_opt *mv, int idx, int id)
{
	if (id)
		ab->len = ab->a_len;
	else
		ab->len = ab->b_len;
	if (ab->len == 2)
	{
		if (id)
			mv->ascore = ab->a_len - idx - 1;
		else
			mv->bscore = ab->b_len - idx - 1;
	}
	else if (idx <= ab->len / 2)
	{
		if (id)
			mv->ascore = idx;
		else
			mv->bscore = idx;
	}
	else
	{
		if (id)
			mv->ascore = ab->a_len - idx;
		else
			mv->bscore = ab->b_len - idx;
	}
}

void	update_score(t_stack *ab, t_opt *mv, int i, int j)
{
	if (mv->ascore + mv->bscore <= mv->optscore)
	{
		mv->aopt = j;
		mv->bopt = i;
		mv->optscore = mv->ascore + mv->bscore;
	}
}

void	move(t_stack *ab, t_opt *mv)
{
	int	a;
	int	b;

	a = ab->a[mv->aopt];
	b = ab->b[mv->bopt];
	move_parll(ab, mv, &a, &b);
	move_seq(ab, mv, &a, &b);
	pa(ab);
}
