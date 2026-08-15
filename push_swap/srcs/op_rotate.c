/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dosong <dosong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 12:51:36 by honam             #+#    #+#             */
/*   Updated: 2026/08/03 15:44:17 by dosong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack *stack)
{
	if (!stack || stack->size < 2)
		return ;
	stack->head = stack->head->next;
	stack->tail = stack->tail->next;
}

void	ra(t_stack *stack_a, int is_silent)
{
	rotate(stack_a);
	if (stack_a->bench)
	{
		stack_a->bench->ra_cnt++;
		stack_a->bench->total_ops++;
	}
	if (is_silent == PRINT)
		write(1, "ra\n", 3);
}

void	rb(t_stack *stack_b, int is_silent)
{
	rotate(stack_b);
	if (stack_b->bench)
	{
		stack_b->bench->rb_cnt++;
		stack_b->bench->total_ops++;
	}
	if (is_silent == PRINT)
		write(1, "rb\n", 3);
}

void	rr(t_stack *stack_a, t_stack *stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	if (stack_a->bench)
	{
		stack_a->bench->rr_cnt++;
		stack_a->bench->total_ops++;
	}
	write(1, "rr\n", 3);
}
