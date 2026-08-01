/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dosong <dosong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 15:00:17 by dosong            #+#    #+#             */
/*   Updated: 2026/07/27 15:00:42 by dosong           ###   ########.fr       */
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
	while (i != stack->tail)
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
	return (mistakes / total_pairs);
}
