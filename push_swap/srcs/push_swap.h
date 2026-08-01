/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dosong <dosong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 15:00:09 by dosong            #+#    #+#             */
/*   Updated: 2026/07/29 12:15:08 by dosong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define PRINT 1
# define SILENT 0
# define INT_MAX 2147483647
# define INT_MIN -2147483648

# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node	*head;
	t_node	*tail;
	int		size;
}	t_stack;

/* utils */
t_stack		*init_stack(void);
void		print_error_and_exit(void);

/* create_stack */
t_node		*create_node(int value);
void		add_last(t_stack *stack, t_node *new_node);

/* check_arg */
int			check_duplicate(t_stack *stack_a, int num);
int			check_num(char *str);
long long	check_overflow(const char *str);
void		check_arg(int argc, char **argv, t_stack *stack_a);

/* parse */
char		*get_strategy(char **argv);
t_stack		*parse(int argc, char **argv, char **strategy);

/* sort_utils */
int			is_sorted(t_stack *stack);
double		compute_disorder(t_stack *stack);

/* operations */
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

/* sort */
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
