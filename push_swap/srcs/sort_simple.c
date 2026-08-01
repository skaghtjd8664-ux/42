/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dosong <dosong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 13:57:46 by dosong            #+#    #+#             */
/*   Updated: 2026/07/27 16:47:34 by dosong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_three(t_stack *a)
{
	int	first;
	int	second;
	int	third;

	first = a->head->value;
	second = a->head->next->value;
	third = a->tail->value;
	if (first > second && second < third && first < third)
		sa(a, PRINT);
	else if (first > second && second > third)
	{
		sa(a, PRINT);
		rra(a, PRINT);
	}
	else if (first > second && second < third && first > third)
		ra(a, PRINT);
	else if (first < second && second > third && first < third)
	{
		sa(a, PRINT);
		ra(a, PRINT);
	}
	else if (first < second && second > third && first > third)
		rra(a, PRINT);
}

static void	sort_insert(t_stack *a, t_stack *b)
{
	int	pos;

	while (a->size > 3)
		pb(a, b);
	sort_three(a);
	while (b->size > 0)
	{
		pos = find_insert_pos(a, b->head->value);
		rotate_a_to_pos(a, pos);
		pa(a, b);
	}
	rotate_a_to_pos(a, find_min_pos(a));
}

void	sort_simple(t_stack *a, t_stack *b)
{
	if (a->size <= 1 || is_sorted(a))
		return ;
	if (a->size == 2)
		sa(a, PRINT);
	else if (a->size == 3)
		sort_three(a);
	else
		sort_insert(a, b);
}
