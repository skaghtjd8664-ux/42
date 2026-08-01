/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dosong <dosong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/19 15:08:15 by honam             #+#    #+#             */
/*   Updated: 2026/07/28 13:13:28 by dosong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*create_node(int value)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = value;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

void	add_last(t_stack *stack, t_node *new_node)
{
	if (!stack || !new_node)
		return ;
	if (stack->size == 0)
	{
		new_node->next = new_node;
		new_node->prev = new_node;
		stack->head = new_node;
		stack->tail = new_node;
	}
	else
	{
		new_node->next = stack->head;
		new_node->prev = stack->tail;
		stack->tail->next = new_node;
		stack->head->prev = new_node;
		stack->tail = new_node;
	}
	stack->size++;
}
