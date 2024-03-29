// push-swap visualisation macros & utilites

#ifndef PUSH_H
#define PUSH_H

# include <stdio.h>
# include <stdlib.h>
# include "raylib.h"
# include "include/libft.h"

# define SCREEN_W 990
# define SCREEN_H 990
# define STACK_SZ 55

typedef struct 	s_opt
{
	int	aopt;		// optimal a indx
	int	bopt;		// optimal b indx
	int ascore;		// current score for target
	int	bscore;		// current score for b
	int	optscore;	// current best score

}				t_opt;

typedef struct	s_stack
{
	int		*a;
	int		*b;
	int		a_len;
	int		b_len;
	int		t_count;
	char	**numbs;
}				t_stack;

int		get_max(int *arr);
int		get_min(int *arr);
int 	rel_w(int n, int min, double diff);
int		set_color(int n, int min, double diff);
//
////////////////////////////////////////////////////
long long	mxi_atoi(const char *nptr);
int			is_ord(int *arr, int len);
int			init_stack(t_stack *ab, int argc, char *argv[]);
int			args_valid_num(char *argv[]);
int			numbs_repeat(int *a, int len);
void		**parse_args(t_stack *ab, int argc, char *argv[]);
int			median(int *arr, int len);
int			min(int *arr, int len);
int			max_idx(int *arr, int len);
int			insert_idx(t_stack *ab);
void		prnt_arr(t_stack *ab);
void		base_c(t_stack *ab);
void		order(t_stack *ab);
void		insert(t_stack *ab);
void		pop_max(t_stack *ab);
void		opt_insert(t_stack *ab);
void		rotate(t_stack *ab);
int			target(t_stack *ab, int idx);
void		score(t_stack *ab, t_opt *mv, int idx, int id);
void		update_score(t_stack *ab, t_opt *mv, int i, int j);
void		move(t_stack *ab, t_opt *mv);
void		move_parll(t_stack *ab, t_opt *mv, int *a, int *b);
void		move_seq(t_stack *ab, t_opt *mv, int *a, int *b);
void		sa(t_stack *ab, int n);
void		sb(t_stack *ab, int n);
void		ss(t_stack *ab);
void		pa(t_stack *ab);
void		pb(t_stack *ab);
void		ra(t_stack *ab, int n);
void		rb(t_stack *ab, int n);
void		rr(t_stack *ab);
void		rra(t_stack *ab, int n);
void		rrb(t_stack *ab, int n);
void		rrr(t_stack *ab);

#endif
