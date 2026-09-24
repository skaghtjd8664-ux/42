/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dosong <dosong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
<<<<<<<< HEAD:push_swap/libft/ft_lstclear.c
/*   Created: 2026/04/26 13:37:41 by dosong            #+#    #+#             */
/*   Updated: 2026/04/26 15:48:48 by dosong           ###   ########.fr       */
========
/*   Created: 2026/07/21 12:51:36 by honam             #+#    #+#             */
/*   Updated: 2026/07/21 13:40:04 by honam            ###   ########.fr       */
>>>>>>>> cf50b79 (finish py02):push_swap/op_rotate.c
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

<<<<<<<< HEAD:push_swap/libft/ft_lstclear.c
void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*cur;

	while (*lst)
	{
		cur = *lst;
		*lst = (*lst)->next;
		ft_lstdelone(cur, del);
	}
	*lst = NULL;
========
void	rotate(t_stack *stack)
{
	if (!stack || stack->size < 2)
		return ;
	stack->head = stack->head->next;
	stack->tail = stack->tail->next;
}

void	ra(t_stack *stack_a, int is_silent)
{
	rotate(stack_a);
	if (is_silent == PRINT)
		write(1, "ra\n", 3);
}

void	rb(t_stack *stack_b, int is_silent)
{
	rotate(stack_b);
	if (is_silent == PRINT)
		write(1, "rb\n", 3);
}

void	rr(t_stack *stack_a, t_stack *stack_b)
{
	ra(stack_a, SILENT);
	rb(stack_b, SILENT);
	write(1, "rr\n", 3);
>>>>>>>> cf50b79 (finish py02):push_swap/op_rotate.c
}
