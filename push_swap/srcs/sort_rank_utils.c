/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_rank_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dosong <dosong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 00:00:00 by dosong            #+#    #+#             */
/*   Updated: 2026/07/29 12:15:00 by dosong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_rank(t_stack *a, t_stack *b, int value)
{
	t_node	*cur;
	int		rank;
	int		i;

	rank = 0;
	cur = a->head;
	i = 0;
	while (i++ < a->size)
	{
		if (cur->value < value)
			rank++;
		cur = cur->next;
	}
	cur = b->head;
	i = 0;
	while (i++ < b->size)
	{
		if (cur->value < value)
			rank++;
		cur = cur->next;
	}
	return (rank);
}

int	get_range(int size)
{
	int	root;

	root = 1;
	while (root * root < size)
		root++;
	return (root * 14 / 10 + 1);
}

int	find_max_pos(t_stack *stack)
{
	t_node	*cur;
	int		max;
	int		pos;
	int		i;

	cur = stack->head;
	max = cur->value;
	pos = 0;
	i = 0;
	while (i < stack->size)
	{
		if (cur->value > max)
		{
			max = cur->value;
			pos = i;
		}
		cur = cur->next;
		i++;
	}
	return (pos);
}

void	rotate_b_to_pos(t_stack *b, int pos)
{
	if (pos <= b->size / 2)
	{
		while (pos-- > 0)
			rb(b, PRINT);
	}
	else
	{
		pos = b->size - pos;
		while (pos-- > 0)
			rrb(b, PRINT);
	}
}
