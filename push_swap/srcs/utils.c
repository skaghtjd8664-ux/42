/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dosong <dosong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/19 13:22:33 by honam             #+#    #+#             */
/*   Updated: 2026/08/05 11:08:22 by dosong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*init_stack(void)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->head = NULL;
	stack->tail = NULL;
	stack->size = 0;
	stack->bench = NULL;
	return (stack);
}

void	print_error_and_exit(t_stack *stack, char **str)
{
	if (stack)
		free_stack(stack);
	if (str)
		free_split(str);
	write(2, "Error\n", 6);
	exit(1);
}

void	free_split(char **str)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	free_stack(t_stack *stack)
{
	t_node	*current;
	t_node	*next_node;
	int		size;

	if (!stack)
		return ;
	current = stack->head;
	size = stack->size;
	while (size > 0)
	{
		next_node = current->next;
		free(current);
		current = next_node;
		size--;
	}
	free(stack);
}
