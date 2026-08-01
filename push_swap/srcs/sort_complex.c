/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dosong <dosong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 15:21:02 by dosong            #+#    #+#             */
/*   Updated: 2026/07/29 12:13:53 by dosong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	set_index(t_stack *a)
{
	t_node	*cur;
	t_node	*cmp;
	int		rank;
	int		i;
	int		j;

	cur = a->head;
	i = 0;
	while (i++ < a->size)
	{
		cmp = a->head;
		rank = 0;
		j = 0;
		while (j++ < a->size)
		{
			if (cmp->value < cur->value)
				rank++;
			cmp = cmp->next;
		}
		cur->index = rank;
		cur = cur->next;
	}
}

static int	get_max_bits(int size)
{
	int	bits;
	int	max;

	bits = 0;
	max = size - 1;
	while ((1 << bits) <= max)
		bits++;
	return (bits);
}

void	sort_complex(t_stack *a, t_stack *b)
{
	int	bits;
	int	max_bits;
	int	i;
	int	size;

	if (a->size <= 5)
	{
		sort_simple(a, b);
		return ;
	}
	set_index(a);
	max_bits = get_max_bits(a->size);
	size = a->size;
	bits = 0;
	while (bits < max_bits)
	{
		i = 0;
		while (i++ < size)
		{
			if ((a->head->index >> bits & 1) == 0)
				pb(a, b);
			else
				ra(a, PRINT);
		}
		while (b->size > 0)
			pa(a, b);
		bits++;
	}
}
