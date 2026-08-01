/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honam <honam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 12:51:36 by honam             #+#    #+#             */
/*   Updated: 2026/07/21 13:40:04 by honam            ###   ########.fr       */
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
	if (is_silent == PRINT)
		write(1, "ra\n", 3);
}

void	rb(t_stack *stack_b, int is_silent)
{
	rotate(stack_b);
	if (is_silent == PRINT)
		write(1, "rb\n", 3);
}

void	rr(t_stack *stack_a, t_stack *stack_b)
{
	ra(stack_a, SILENT);
	rb(stack_b, SILENT);
	write(1, "rr\n", 3);
}
