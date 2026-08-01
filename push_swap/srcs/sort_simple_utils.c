/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dosong <dosong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 17:37:00 by dosong            #+#    #+#             */
/*   Updated: 2026/07/27 17:37:00 by dosong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min_pos(t_stack *stack)
{
	t_node	*cur;
	int		min;
	int		pos;
	int		i;

	cur = stack->head;
	min = cur->value;
	pos = 0;
	i = 0;
	while (i < stack->size)
	{
		if (cur->value < min)
		{
			min = cur->value;
			pos = i;
		}
		cur = cur->next;
		i++;
	}
	return (pos);
}

int	find_insert_pos(t_stack *a, int value)
{
	t_node	*cur;
	t_node	*next;
	int		i;

	cur = a->head;
	i = 0;
	while (i < a->size)
	{
		next = cur->next;
		if (cur->value < value && value < next->value)
			return ((i + 1) % a->size);
		cur = cur->next;
		i++;
	}
	return (find_min_pos(a));
}

void	rotate_a_to_pos(t_stack *a, int pos)
{
	if (pos <= a->size / 2)
	{
		while (pos-- > 0)
			ra(a, PRINT);
	}
	else
	{
		pos = a->size - pos;
		while (pos-- > 0)
			rra(a, PRINT);
	}
}
