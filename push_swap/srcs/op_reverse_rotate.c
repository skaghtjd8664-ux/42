/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dosong <dosong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 13:06:09 by honam             #+#    #+#             */
/*   Updated: 2026/08/03 15:45:55 by dosong           ###   ########.fr       */
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
	if (stack_a->bench)
	{
		stack_a->bench->rra_cnt++;
		stack_a->bench->total_ops++;
	}
	if (is_silent == PRINT)
		write(1, "rra\n", 4);
}

void	rrb(t_stack *stack_b, int is_silent)
{
	reverse_rotate(stack_b);
	if (stack_b->bench)
	{
		stack_b->bench->rrb_cnt++;
		stack_b->bench->total_ops++;
	}
	if (is_silent == PRINT)
		write(1, "rrb\n", 4);
}

void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	if (stack_a->bench)
	{
		stack_a->bench->rrr_cnt++;
		stack_a->bench->total_ops++;
	}
	write(1, "rrr\n", 4);
}
