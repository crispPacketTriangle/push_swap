/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lworden <lworden@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 21:01:48 by lworden           #+#    #+#             */
/*   Updated: 2024/04/13 20:16:12 by lworden          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	*ab;
	t_stack	stack;

	ab = &stack;
	if (argc < 2)
		return (0);
	set_ab_null(ab);
	if (init_stack(ab, argc, argv))
	{
		free_arrs(argc, ab);
		ft_printf("Error!\n");
		return (0);
	}
	ab->b_len = 0;
	ab->b = malloc(ab->a_len * sizeof(int));
	if (!ab->b)
	{
		free_arrs(argc, ab);
		ft_printf("Error!\n");
		return (0);
	}
	ord_stack(ab);
	//printresults(ab);
	free_arrs(argc, ab);
}

int	ord_stack(t_stack *ab)
{
	ab->t_count = 0;
	if (is_ord(ab->a, ab->a_len))
		return (0);
	if (ab->a_len < 25)
	{
		while (ab->a_len > 3)
		{
			if (ab->a_len - 1 == max_idx(ab->a, ab->a_len))
				ra(ab, 1);
			else
				pb(ab);
		}
		base_c(ab);
	}
	else
	{
		while (ab->a_len > 0)
			order(ab);
		pop_max(ab);
	}
	while (ab->b_len > 0)
		opt_insert(ab);
	rotate(ab);
	return (1);
}

void	set_ab_null(t_stack *ab)
{
	ab->a = NULL;
	ab->b = NULL;
}

// remember to free everything when returning with errors
// perhaps free_err() func
void	free_arrs(int argc, t_stack *ab)
{
	int	i;

	if (argc == 2)
	{
		i = 0;
		while (ab->numbs[i])
		{
			free(ab->numbs[i]);
			i++;
		}
		free(ab->numbs);
	}
	free(ab->a);
	free(ab->b);
}

void	prnt_arr(t_stack *ab)
{
	int	i;

	ft_printf("a:\n");
	i = 0;
	while (i < ab->a_len)
	{
		ft_printf(" %d -", ab->a[i]);
		i++;
	}
	ft_printf("\nb:\n");
	i = 0;
	while (i < ab->b_len)
	{
		ft_printf(" %d -", ab->b[i]);
		i++;
	}
	ft_printf("\n");
}

void	printresults(t_stack *ab)
{
	ft_printf("----------------result--------------\n");
	prnt_arr(ab);
	//ft_printf("\n");
	//ft_printf("n ops: %d\n", ab->t_count);
	if (is_ord(ab->a, ab->a_len))
		ft_printf("yes\n");
	else
		ft_printf("no\n");
	ft_printf("------------------------------------\n");
}
