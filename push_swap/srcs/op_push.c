/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dosong <dosong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 12:14:23 by honam             #+#    #+#             */
/*   Updated: 2026/08/04 14:09:30 by dosong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_top(t_stack *dest, t_node *temp)
{
	if (dest->head == NULL)
	{
		temp->next = temp;
		temp->prev = temp;
		dest->head = temp;
		dest->tail = temp;
	}
	else
	{
		temp->next = dest->head;
		temp->prev = dest->tail;
		dest->head->prev = temp;
		dest->tail->next = temp;
		dest->head = temp;
	}
	dest->size++;
}

void	push(t_stack *dest, t_stack *src)
{
	t_node	*temp;

	if (!dest || !src || src->size == 0)
		return ;
	temp = src->head;
	if (src->size == 1)
	{
		src->head = NULL;
		src->tail = NULL;
	}
	else
	{
		src->head = temp->next;
		src->head->prev = src->tail;
		src->tail->next = src->head;
	}
	src->size--;
	push_top(dest, temp);
}

void	pa(t_stack *stack_a, t_stack *stack_b)
{
	push(stack_a, stack_b);
	if (stack_a->bench)
	{
		stack_a->bench->pa_cnt++;
		stack_a->bench->total_ops++;
	}
	write(1, "pa\n", 3);
}

void	pb(t_stack *stack_a, t_stack *stack_b)
{
	push(stack_b, stack_a);
	if (stack_a->bench)
	{
		stack_a->bench->pb_cnt++;
		stack_a->bench->total_ops++;
	}
	write(1, "pb\n", 3);
}
