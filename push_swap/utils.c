/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honam <honam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/19 13:22:33 by honam             #+#    #+#             */
/*   Updated: 2026/07/21 15:02:14 by honam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*init_stack(void)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	stack->head = NULL;
	stack->tail = NULL;
	stack->size = 0;
	return (stack);
}

void	print_error(t_stack *stack)
{
	write(1, "Error\n", 6);
	exit(1);
}
