/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dosong <dosong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
<<<<<<<< HEAD:push_swap/libft/ft_putstr_fd.c
/*   Created: 2026/04/11 16:41:34 by dosong            #+#    #+#             */
/*   Updated: 2026/04/11 16:53:03 by dosong           ###   ########.fr       */
========
/*   Created: 2026/07/21 13:06:09 by honam             #+#    #+#             */
/*   Updated: 2026/07/21 13:40:17 by honam            ###   ########.fr       */
>>>>>>>> cf50b79 (finish py02):push_swap/op_reverse_rotate.c
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_stack *stack)
{
<<<<<<<< HEAD:push_swap/libft/ft_putstr_fd.c
	if (!s)
		return ;
	while (*s)
		write(fd, s++, 1);
========
	if (!stack || stack->size < 2)
		return ;
	stack->head = stack->head->prev;
	stack->tail = stack->tail->prev;
}

void	rra(t_stack *stack_a, int is_silent)
{
	reverse_rotate(stack_a);
	if (is_silent == PRINT)
		write(1, "rra\n", 4);
}

void	rrb(t_stack *stack_b, int is_silent)
{
	reverse_rotate(stack_b);
	if (is_silent == PRINT)
		write(1, "rrb\n", 4);
}

void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	rra(stack_a, SILENT);
	rrb(stack_b, SILENT);
	write(1, "rrr\n", 4);
>>>>>>>> cf50b79 (finish py02):push_swap/op_reverse_rotate.c
}
