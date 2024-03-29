#include "push_swap.h"
 
// min value in a above value at top of b
// calculate cost of insertion for each element in stack b
// gcc push_swap.c r_utils.c rr_utils.c ab_utils.c push_utils.c -I ./include/ -L ./lib/ -lraylib -lGL -lX11 -lm && clear && ./a.out

// include libft
// gcc push_swap.c r_utils.c rr_utils.c ab_utils.c push_utils.c -I ./libft -L -llibft -I ./include/ -L ./lib/ -lraylib -lGL -lX11 -lm

int g_avg_score;

// could add a further optimisation by rotating ab->b in initial stage if ab->a rotating,
// in case where value on top of b is lower than the median for ab->b

// the programme should do nothing if the stack is already ordered
// the way ints should be passed to the programme is in reverse order to my implementation
// beware of this when parsing

// 3 arguments should be sorted in no more than 3 moves
// 5 in no more than 12

// something odd happeing with makefile where changes happening but ... oh should make re
// or else binary remains
//
// avg moves strange because takes account of initial bucket sort for lengths above 5

int	main(int argc, char *argv[])
{
	t_stack *ab;
	t_stack stack;

	ab = &stack;
	if (argc < 2)
		return (0);
	if (init_stack(ab, argc, argv))
	{
		ft_printf("Error!\n");
		return (0);
	}
	ab->b_len = 0;
	ab->b = malloc(ab->a_len * sizeof(int));
	ab->t_count = 0;
	/////////////////////////////////////////////////////

	ft_printf("------------------------------------\n");
	prnt_arr(ab);
	ft_printf("------------------------------------\n");
	
	//////////// abstract to sep func ///////////////////
	if (is_ord(ab->a, ab->a_len))
		return (0);
	if (ab->a_len < 25)
	{
		while (ab->a_len > 3)
			if (ab->a_len - 1 == max_idx(ab->a, ab->a_len))
				ra(ab, 1);
			else
				pb(ab);
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

	////////////////////////////////////////////////////
	ft_printf("----------------result--------------\n");
	prnt_arr(ab);
	ft_printf("\n");
	ft_printf("n ops: %d\n", ab->t_count);
	ft_printf("avg moves: %d\n", (g_avg_score + (ab->a_len * 2)) / ab->a_len);
	if (is_ord(ab->a, ab->a_len))
		ft_printf("yes\n");
	else
		ft_printf("no\n");
	ft_printf("------------------------------------\n");

	/////////// abstract into sep func /////////////////
	if (argc == 2)
	{
		int i;
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
	////////////////////////////////////////////////////
}

int	init_stack(t_stack *ab, int argc, char *argv[])
{
// Run push_swap with non numeric parameters. The program must
// display "Error". -> 1   ####################################
//
// Run push_swap with a duplicate numeric parameter. The program
// must display "Error". -> 1 #################################
//
// Run push_swap with only numeric parameters including one greater
// than MAXINT. The program must display "Error". -> 1
//
// 		- the input could be any number greater than MAXINT
// 		must then modify ft_atoi
// 		rather than using a an int for sum use a long long and check
// 		for MAX
//
// 		remember to free everything when returning with errors
//
// Run push_swap without any parameters. The program must not
// display anything and give the prompt back -> 2 ##############
	int			i;
	long long	chk_mx;

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
	i = 0;
	while (i < ab->a_len)
	{
		chk_mx = mxi_atoi(ab->numbs[i]);
		if (chk_mx > 2147483647 || chk_mx < -2147483648)
			return (1);
		ab->a[ab->a_len - 1 - i] = chk_mx;
		i++;
	}
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
	// deal with leading + or -
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
// input can be either args to argv or a list of ints as a single string
// variable str len -> ft_isdigit
void	**parse_args(t_stack *ab, int argc, char *argv[])
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
		j = target(ab, i);		// target for b value (return indx)
		score(ab, mv, i, 0);	// score for b value (last argument to tell score which values to update, a or b)
		score(ab, mv, j, 1);	// score for a value
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
	int	len;

	if (id)
		len = ab->a_len;
	else
		len = ab->b_len;
	if (len == 2)
		if (id)
			mv->ascore = ab->a_len - idx - 1;
		else
			mv->bscore = ab->b_len - idx - 1;
	else if (idx <= len / 2)  // <= in relation to updating score with only 3 values
		if (id)
			mv->ascore = idx;
		else
			mv->bscore = idx;
	else
		if (id)
			mv->ascore = ab->a_len - idx;
		else
			mv->bscore = ab->b_len - idx ;
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
	int a;
	int b;
	a = ab->a[mv->aopt];
	b = ab->b[mv->bopt];

	g_avg_score += mv->optscore;
	move_parll(ab, mv, &a, &b);
	move_seq(ab, mv, &a, &b);
	pa(ab);
}

// TODO - split function
// 		if 0 1  1  if sum 1, func calls list 0 1
//		if 1 1  2  if sum 2, func calls list 2
//		if 1 0  1  if sum 1, func calls list 1 0
//		if 0 0  0  if sum 0, func calls list 3
void	move_parll(t_stack *ab, t_opt *mv, int *a, int *b)
{
	int	calls[2];

	if (mv->aopt >= ab->a_len / 2)
		calls[0] = 0;
	else
		calls[0] = 1;
	if (mv->bopt >= ab->b_len / 2)
		calls[1] = 0;
	else
		calls[1] = 1;
	if (calls[0] + calls[1] == 0)
		while (ab->a[ab->a_len -1] != *a && ab->b[ab->b_len - 1] != *b)
			rr(ab);
	else if (calls[0] + calls[1] == 2)
		while (ab->a[ab->a_len -1] != *a && ab->b[ab->b_len - 1] != *b)
			rrr(ab);
}

// move sequentially
void	move_seq(t_stack *ab, t_opt *mv, int *a, int *b)
{
	while (ab->a[ab->a_len - 1] != *a)
	{
		if (mv->aopt >= ab->a_len / 2) // >= or == see notes
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

// min value in a above value at top of b
// int	insert_idx(t_stack *ab)
// {
// 	int	i;
// 	int	val;
// 	int idx;
// 	
// 	idx = 0;
// 	i = 0;
// 	val = ab->a[max_idx(ab->a, ab->a_len)];
// 	while (i < ab->a_len)
// 	{
// 		if  (ab->a[i] < val && (ab->a[i] > ab->b[ab->b_len - 1]))
// 		{
// 			val = ab->a[i];
// 			idx = i;
// 		}
// 		i++;
// 	}
// 	return (idx);
// }

void	order(t_stack *ab)
{
	int	med;
	int	seg;

	seg = ab->a_len / 2;
	med = median(ab->a, ab->a_len);
	//ft_printf("med: %d\n", med);
	while (ab->a_len > seg)
	{
		if (ab->a[ab->a_len - 1] <= med)
			pb(ab);
		else
		{
			// is item at top of b smaller than min item in b
			// if ((seg == STACK_SZ / 2) && ab->b[ab->b_len - 1] < median(ab->b, ab->b_len))
			// 	rr(ab);
			// else
				ra(ab, 1);
		}
	}
}

// void	insert(t_stack *ab)
// {
// 	int	nxt;
// 	int	val;
//
// 	nxt = max_idx(ab->b, ab->b_len);
// 	val = ab->b[nxt];
// 	if (nxt < ab->b_len / 2)
// 	{
// 		while (ab->b[ab->b_len - 1] != val)
// 			rrb(ab, 1);
// 		pa(ab);
// 	}	
// 	else
// 	{
// 		while (ab->b[ab->b_len - 1] != val)
// 			rb(ab, 1);
// 		pa(ab);
// 	}
// }

// t_opers	*init()
// {
// 	t_opers	*op;
// 	op = malloc(sizeof(t_opers));
// 	op->n[0] = sa;
// 	op->n[1] = sb;
// 	op->n[2] = ss;
// 	op->n[3] = pa;
// 	op->n[4] = pb;
// 	op->n[5] = ra;
// 	op->n[6] = rb;
// 	op->n[7] = rr;
// 	op->n[8] = rra;
// 	op->n[9] = rrb;
// 	op->n[10] = rrr;
// 	return (op);
// }

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
	int val;
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
	int val;

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
	// because of initial bucket sort will always be
	// either top or -1
	while (ab->b[ab->b_len - 1] != val)
	{
		rb(ab, 1);
	}
	pa(ab);
}

int	min(int *arr, int len)
{
	int	i;
	int val;
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

