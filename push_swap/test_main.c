/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honam <honam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 10:36:01 by honam             #+#    #+#             */
/*   Updated: 2026/07/21 13:49:42 by honam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	print_stack(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*current_a;
	t_node	*current_b;
	int		i;
	int		j;

	if (!stack_a || !stack_b)
		return ;
	current_a = stack_a->head;
	i = 0;
	printf("a | ");
	while (i < stack_a->size)
	{
		printf("%d ", current_a->value);
		current_a = current_a->next;
		i++;
	}
	printf("\n");
	current_b = stack_b->head;
	j = 0;
	printf("b | ");
	while (j < stack_b->size)
	{
		printf("%d ", current_b->value);
		current_b = current_b->next;
		j++;
	}
	printf("\n");
}

int	main(void)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = init_stack();
	stack_b = init_stack();
	if (!stack_a || !stack_b)
		return (1);
	add_last(stack_a, create_node(2));
	add_last(stack_a, create_node(1));
	add_last(stack_a, create_node(3));
	add_last(stack_a, create_node(6));
	add_last(stack_a, create_node(5));
	add_last(stack_a, create_node(8));
	print_stack(stack_a, stack_b);

	sa(stack_a, PRINT);
	print_stack(stack_a, stack_b);

	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	print_stack(stack_a, stack_b);

	rr(stack_a, stack_b);
	print_stack(stack_a, stack_b);

	rrr(stack_a, stack_b);
	print_stack(stack_a, stack_b);

	sa(stack_a, PRINT);
	print_stack(stack_a, stack_b);

	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
	print_stack(stack_a, stack_b);
	return (0);
}
