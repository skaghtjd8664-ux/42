/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dosong <dosong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
<<<<<<<< HEAD:push_swap/libft/ft_lstadd_back.c
/*   Created: 2026/04/14 15:32:46 by dosong            #+#    #+#             */
/*   Updated: 2026/04/14 15:47:40 by dosong           ###   ########.fr       */
========
/*   Created: 2026/07/19 13:22:33 by honam             #+#    #+#             */
/*   Updated: 2026/07/21 15:02:14 by honam            ###   ########.fr       */
>>>>>>>> cf50b79 (finish py02):push_swap/utils.c
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*init_stack(void)
{
<<<<<<<< HEAD:push_swap/libft/ft_lstadd_back.c
	t_list	*begin;

	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	begin = *lst;
	while (begin->next)
		begin = begin -> next;
	begin->next = new;
========
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
>>>>>>>> cf50b79 (finish py02):push_swap/utils.c
}
