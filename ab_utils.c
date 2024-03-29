#include "push_swap.h"

// swap first 2 elements at the top of stack a
void	sa(t_stack *ab, int n)
{
	int	temp;

	if (ab->a_len > 1)
	{
		temp = ab->a[ab->a_len - 1];
		ab->a[ab->a_len - 1] = ab->a[ab->a_len - 2];
		ab->a[ab->a_len - 2] = temp;
	}
	if (n)
		printf("sa\n");
	ab->t_count++;
}

// swap first 2 elements at the top of stack b
void	sb(t_stack *ab, int n)
{
	int	temp;

	if (ab->b_len > 1)
	{
		temp = ab->b[ab->b_len - 1];
		ab->b[ab->b_len - 1] = ab->b[ab->b_len - 2];
		ab->b[ab->b_len - 2] = temp;
	}
	if (n)
		printf("sb\n");
	ab->t_count++;
}

// sa and sb at the same time
void	ss(t_stack *ab)
{
	sa(ab, 0);
	sb(ab, 0);
	printf("ss\n");
	ab->t_count--;
}

// take first element at the top of b and put it at the top of a
void	pa(t_stack *ab)
{
	if (ab->b_len > 0)
	{
		ab->a[ab->a_len] = ab->b[ab->b_len - 1];
		ab->a_len++;
		ab->b_len--;
	}
	printf("pa\n");
	ab->t_count++;
}

// take first element at the top of a and put it at the top of b
void	pb(t_stack *ab)
{
	if (ab->a_len > 0)
	{
		ab->b[ab->b_len] = ab->a[ab->a_len - 1];
		ab->b_len++;
		ab->a_len--;
	}
	printf("pb\n");
	ab->t_count++;
}

