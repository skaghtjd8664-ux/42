/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dosong <dosong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 15:00:17 by dosong            #+#    #+#             */
/*   Updated: 2026/08/03 16:37:40 by dosong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *stack)
{
	t_node	*cur;

	if (!stack || stack->size <= 1)
		return (1);
	cur = stack->head;
	while (cur->next != stack->head)
	{
		if (cur->value > cur->next->value)
			return (0);
		cur = cur->next;
	}
	return (1);
}

double	compute_disorder(t_stack *stack)
{
	t_node	*i;
	t_node	*j;
	double	mistakes;
	double	total_pairs;

	mistakes = 0;
	total_pairs = 0;
	i = stack->head;
	while (i != stack->tail && stack->size > 1)
	{
		j = i->next;
		while (j != stack->head)
		{
			total_pairs++;
			if (i->value > j->value)
				mistakes++;
			j = j->next;
		}
		i = i->next;
	}
	if (total_pairs == 0)
		return (0);
	return ((mistakes / total_pairs) * 100.0);
}

static void	print_op(char *name, int cnt, char end)
{
	ft_putstr_fd(name, 2);
	ft_putnbr_fd(cnt, 2);
	ft_putchar_fd(end, 2);
}

static void	print_bench_ops(t_bench *b)
{
	print_op("[bench] sa: ", b->sa_cnt, ' ');
	print_op("sb: ", b->sb_cnt, ' ');
	print_op("ss: ", b->ss_cnt, ' ');
	print_op("pa: ", b->pa_cnt, ' ');
	print_op("pb: ", b->pb_cnt, '\n');
	print_op("[bench] ra: ", b->ra_cnt, ' ');
	print_op("rb: ", b->rb_cnt, ' ');
	print_op("rr: ", b->rr_cnt, ' ');
	print_op("rra: ", b->rra_cnt, ' ');
	print_op("rrb: ", b->rrb_cnt, ' ');
	print_op("rrr: ", b->rrr_cnt, '\n');
}

void	print_bench_stats(t_bench *b)
{
	int	dec_part;

	if (!b->is_bench)
		return ;
	dec_part = (int)((b->disorder - (int)b->disorder) * 100);
	print_op("[bench] disorder: ", (int)b->disorder, '.');
	if (dec_part < 10)
		ft_putchar_fd('0', 2);
	print_op("", dec_part, '%');
	ft_putchar_fd('\n', 2);
	ft_putstr_fd("[bench] strategy: ", 2);
	ft_putstr_fd(b->strategy, 2);
	ft_putstr_fd(" / ", 2);
	ft_putstr_fd(b->complexity, 2);
	ft_putchar_fd('\n', 2);
	print_op("[bench] total_ops: ", b->total_ops, '\n');
	print_bench_ops(b);
}
