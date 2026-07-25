/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honam <honam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/17 15:19:00 by honam             #+#    #+#             */
/*   Updated: 2026/07/25 16:52:13 by honam            ###   ########.fr       */
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

int		set_stack_index(int value);
t_node	*create_node(int value);
void	add_last(t_stack *stack, t_node *new_node);
void	add_first(t_stack *stack, t_node *new_node);

//op
void	swap(t_stack *stack);
void	sa(t_stack *stack_a, int is_silent);
void	sb(t_stack *stack_b, int is_silent);
void	ss(t_stack *stack_a, t_stack *stack_b);

void	push(t_stack *dst, t_stack *src);
void	pa(t_stack *stack_a, t_stack *stack_b);
void	pb(t_stack *stack_a, t_stack *stack_b);

void	rotate(t_stack *stack);
void	ra(t_stack *stack_a, int is_silent);
void	rb(t_stack *stack_b, int is_silent);
void	rr(t_stack *stack_a, t_stack *stack_b);

void	reverse_rotate(t_stack *stack);
void	rra(t_stack *stack_a, int is_silent);
void	rrb(t_stack *stack_b, int is_silent);
void	rrr(t_stack *stack_a, t_stack *stack_b);

//utils
size_t	ft_strlen(const char *str);
t_stack	*init_stack(void);
void	print_error_and_exit(char *s);
int		ft_isdigit(int c);
int		ft_atoi(char *str);

char	**ft_split(char const *s, char c);

int		check_duplicate(int *arr, int size);
int		check_arg(int *arg);

void	ft_free(int *arr);

#endif
