/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dosong <dosong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/16 15:21:02 by dosong            #+#    #+#             */
/*   Updated: 2026/08/03 14:42:36 by dosong           ###   ########.fr       */
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

static void	execute_radix_pass(t_stack *a, t_stack *b, int bit)
{
	int	i;
	int	size;

	i = 0;
	size = a->size;
	while (i++ < size)
	{
		if ((a->head->index >> bit & 1) == 0)
			pb(a, b);
		else
			ra(a, PRINT);
	}
	while (b->size > 0)
		pa(a, b);
}

void	sort_complex(t_stack *a, t_stack *b)
{
	int	bits;
	int	max_bits;

	if (a->size <= 5)
	{
		sort_simple(a, b);
		return ;
	}
	set_index(a);
	max_bits = get_max_bits(a->size);
	bits = 0;
	while (bits < max_bits)
	{
		execute_radix_pass(a, b, bits);
		bits++;
	}
}
