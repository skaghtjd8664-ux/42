/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honam <honam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 13:06:09 by honam             #+#    #+#             */
/*   Updated: 2026/07/21 13:40:17 by honam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_stack *stack)
{
	if (!stack || stack->size < 2)
		return ;
	stack->head = stack->head->prev;
	stack->tail = stack->tail->prev;
}

void	rra(t_stack *stack_a, int is_silent)
{
	reverse_rotate(stack_a);
	if (is_silent == PRINT)
		write(1, "rra\n", 4);
}

void	rrb(t_stack *stack_b, int is_silent)
{
	reverse_rotate(stack_b);
	if (is_silent == PRINT)
		write(1, "rrb\n", 4);
}

void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	rra(stack_a, SILENT);
	rrb(stack_b, SILENT);
	write(1, "rrr\n", 4);
}
