/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honam <honam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/19 15:08:15 by honam             #+#    #+#             */
/*   Updated: 2026/07/22 14:30:44 by honam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	set_index(t_stack *stack, int value, int size)
{
	t_node	*current;
	int		i;

	if (!stack || stack->size == 0)
		return (-1);
	current = stack->head;
	i = -1;
	while (i < size)
	{
		if (current->value == value)
			return (i);
		current = current->next;
		i++;
	}
	return (-1);
}

t_node	*create_node(int value)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = value;
	node->index = -1;
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
		stack->head = new_node;
		stack->tail = new_node;
	}
	else
	{
		stack->tail->next = new_node;
		new_node->prev = stack->tail;
		new_node->next = stack->head;
		stack->head->prev = new_node;
		stack->tail = new_node;
	}
	stack->size++;
}
