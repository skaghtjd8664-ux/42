/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dosong <dosong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 15:00:09 by dosong            #+#    #+#             */
/*   Updated: 2026/08/05 16:10:46 by dosong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define PRINT 1
# define INT_MAX 2147483647
# define INT_MIN -2147483648

# include <stdlib.h>
# include <unistd.h>
# include "libft.h"
# include "ft_printf.h"

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_bench
{
	int		is_bench;
	double	disorder;
	char	*strategy;
	char	*complexity;
	int		total_ops;
	int		sa_cnt;
	int		sb_cnt;
	int		ss_cnt;
	int		pa_cnt;
	int		pb_cnt;
	int		ra_cnt;
	int		rb_cnt;
	int		rr_cnt;
	int		rra_cnt;
	int		rrb_cnt;
	int		rrr_cnt;
}	t_bench;

typedef struct s_stack
{
	t_node			*head;
	t_node			*tail;
	int				size;
	struct s_bench	*bench;
}	t_stack;

void		print_bench_stats(t_bench *bench);
t_stack		*init_stack(void);
void		print_error_and_exit(t_stack *stack, char **str);
void		free_split(char **str);
void		free_stack(t_stack *stack);
t_node		*create_node(int value);
void		add_last(t_stack *stack, t_node *new_node);
int			check_duplicate(t_stack *stack_a, int num);
int			check_num(char *str);
long long	check_overflow(const char *str);
void		check_arg(int argc, char **argv, t_stack *stack_a);
t_stack		*parse(int argc, char **argv, char **strategy);
int			check_bench_flag(int argc, char **argv);
int			is_sorted(t_stack *stack);
double		compute_disorder(t_stack *stack);
void		swap(t_stack *stack);
void		sa(t_stack *stack_a, int is_silent);
void		sb(t_stack *stack_b, int is_silent);
void		ss(t_stack *stack_a, t_stack *stack_b);
void		push(t_stack *dst, t_stack *src);
void		pa(t_stack *stack_a, t_stack *stack_b);
void		pb(t_stack *stack_a, t_stack *stack_b);
void		rotate(t_stack *stack);
void		ra(t_stack *stack_a, int is_silent);
void		rb(t_stack *stack_b, int is_silent);
void		rr(t_stack *stack_a, t_stack *stack_b);
void		reverse_rotate(t_stack *stack);
void		rra(t_stack *stack_a, int is_silent);
void		rrb(t_stack *stack_b, int is_silent);
void		rrr(t_stack *stack_a, t_stack *stack_b);
int			find_min_pos(t_stack *stack);
int			find_insert_pos(t_stack *a, int value);
void		rotate_a_to_pos(t_stack *a, int pos);
int			get_rank(t_stack *a, t_stack *b, int value);
int			get_range(int size);
int			find_max_pos(t_stack *stack);
void		rotate_b_to_pos(t_stack *b, int pos);
void		sort_simple(t_stack *stack_a, t_stack *stack_b);
void		sort_medium(t_stack *stack_a, t_stack *stack_b);
void		sort_complex(t_stack *stack_a, t_stack *stack_b);

#endif
