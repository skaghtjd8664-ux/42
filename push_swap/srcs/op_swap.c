/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dosong <dosong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/19 17:26:41 by honam             #+#    #+#             */
/*   Updated: 2026/08/03 16:02:46 by dosong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stack)
{
	int	temp;

	if (!stack || stack->size < 2)
		return ;
	temp = stack->head->value;
	stack->head->value = stack->head->next->value;
	stack->head->next->value = temp;
}

void	sa(t_stack *stack_a, int is_silent)
{
	swap(stack_a);
	if (stack_a->bench)
	{
		stack_a->bench->sa_cnt++;
		stack_a->bench->total_ops++;
	}
	if (is_silent == PRINT)
		write(1, "sa\n", 3);
}

void	sb(t_stack *stack_b, int is_silent)
{
	swap(stack_b);
	if (stack_b->bench)
	{
		stack_b->bench->sb_cnt++;
		stack_b->bench->total_ops++;
	}
	if (is_silent == PRINT)
		write(1, "sb\n", 3);
}

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	swap(stack_a);
	swap(stack_b);
	if (stack_a->bench)
	{
		stack_a->bench->ss_cnt++;
		stack_a->bench->total_ops++;
	}
	write(1, "ss\n", 3);
}
