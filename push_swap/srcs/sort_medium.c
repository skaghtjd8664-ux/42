/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dosong <dosong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 15:21:12 by dosong            #+#    #+#             */
/*   Updated: 2026/07/28 12:13:13 by dosong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_by_hourglass(t_stack *a, t_stack *b, int range)
{
	int	pushed;
	int	rank;

	pushed = 0;
	while (a->size > 0)
	{
		rank = get_rank(a, b, a->head->value);
		if (rank <= pushed)
		{
			pb(a, b);
			pushed++;
			if (b->size > 1)
				rb(b, PRINT);
		}
		else if (rank <= pushed + range)
		{
			pb(a, b);
			pushed++;
		}
		else
			ra(a, PRINT);
	}
}

static void	push_back_by_max(t_stack *a, t_stack *b)
{
	while (b->size > 0)
	{
		rotate_b_to_pos(b, find_max_pos(b));
		pa(a, b);
	}
}

void	sort_medium(t_stack *a, t_stack *b)
{
	if (a->size <= 5)
	{
		sort_simple(a, b);
		return ;
	}
	push_by_hourglass(a, b, get_range(a->size));
	push_back_by_max(a, b);
}
