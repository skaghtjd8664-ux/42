/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dosong <dosong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 15:32:46 by dosong            #+#    #+#             */
/*   Updated: 2026/04/14 15:47:40 by dosong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
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
}
