/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honam <honam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/19 17:26:41 by honam             #+#    #+#             */
/*   Updated: 2026/07/21 10:35:53 by honam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stack)
{
	t_node	*first;
	t_node	*second;

	if (!stack || stack->size < 2)
		return ;
	first = stack->head;
	second = first->next;

	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	first->prev = second;
	second->next = first;
	second->prev = first->prev;

	stack->head = second;
	if (stack->tail == second)
		stack->tail = first;
}

void	sa(t_stack *stack_a, int is_silent)
{
	swap(stack_a);
	if (is_silent == PRINT)
		write(1, "sa\n", 3);
}

void	sb(t_stack *stack_b, int is_silent)
{
	swap(stack_b);
	if (is_silent == PRINT)
		write(1, "sb\n", 3);
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	sa(stack_a, SILENT);
	sb(stack_b, SILENT);
	write(1, "ss\n", 3);
}
