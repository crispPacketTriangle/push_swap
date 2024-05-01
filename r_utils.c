/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lworden <lworden@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 21:54:54 by lworden           #+#    #+#             */
/*   Updated: 2024/03/29 21:54:57 by lworden          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// ra (rotate a): Shift up all elements of stack a by 1
// first element becomes last
void	ra(t_stack *ab, int n)
{
	int	temp;
	int	i;

	i = 0;
	if (ab->a_len > 1)
		temp = ab->a[ab->a_len -1];
	while (i < ab->a_len - 1)
	{
		ab->a[ab->a_len - (i + 1)] = ab->a[ab->a_len - (i + 2)];
		i++;
	}
	ab->a[0] = temp;
	if (n)
		ft_printf("ra\n");
	ab->t_count++;
}

// rb (rotate b): Shift up all elements of stack b by 1
void	rb(t_stack *ab, int n)
{
	int	temp;
	int	i;

	i = 0;
	if (ab->b_len > 1)
		temp = ab->b[ab->b_len -1];
	while (i < ab->b_len - 1)
	{
		ab->b[ab->b_len - (i + 1)] = ab->b[ab->b_len - (i + 2)];
		i++;
	}
	ab->b[0] = temp;
	if (n)
		ft_printf("rb\n");
	ab->t_count++;
}

void	rr(t_stack *ab)
{
	ra(ab, 0);
	rb(ab, 0);
	ft_printf("rr\n");
	ab->t_count--;
}
