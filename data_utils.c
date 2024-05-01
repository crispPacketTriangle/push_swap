/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lworden <lworden@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 21:12:03 by lworden           #+#    #+#             */
/*   Updated: 2024/04/13 19:32:26 by lworden          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	init_stack(t_stack *ab, int argc, char *argv[])
{
	parse_args(ab, argc, argv);
	if (args_valid_num(ab->numbs))
		return (1);
	ab->a_len = 0;
	if (argc == 2)
		while (ab->numbs[ab->a_len])
			ab->a_len++;
	else
		ab->a_len = argc - 1;
	ab->a = malloc(ab->a_len * sizeof(int));
	if (!ab->a)
		return (1);
	if (stack_ins(ab))
		return (1);
	if (numbs_repeat(ab->a, ab->a_len))
		return (1);
	return (0);
}

int	numbs_repeat(int *a, int len)
{
	int	i;
	int	j;
	int	target;

	i = 0;
	j = 0;
	while (i < len)
	{
		j = 0;
		target = a[i];
		while (j < len)
		{
			if (j != i && a[j] == target)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	args_valid_num(char **numbs)
{
	int		n;
	int		m;

	n = 0;
	while (numbs[n])
	{
		m = 0;
		if (numbs[n][m] == '-' || numbs[n][m] == '+')
			m++;
		while (numbs[n][m])
		{
			if (!ft_isdigit(numbs[n][m]))
				return (1);
			m++;
		}
		n++;
	}
	return (0);
}

void	parse_args(t_stack *ab, int argc, char *argv[])
{
	if (argc == 2)
	{
		ab->numbs = ft_split(argv[1], ' ');
	}
	if (argc > 2)
		ab->numbs = &argv[1];
}

void	base_c(t_stack *ab)
{
	if (ab->a[2] == min(ab->a, ab->a_len))
		ra(ab, 1);
	if (ab->a[1] == min(ab->a, ab->a_len))
	{
		if (ab->a[2] < ab->a[0])
		{
			sa(ab, 1);
			return ;
		}
		else
			rra(ab, 1);
	}
	if (ab->a[2] > ab->a[1])
		sa(ab, 1);
	rra(ab, 1);
}
