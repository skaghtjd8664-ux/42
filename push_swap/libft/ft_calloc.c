/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dosong <dosong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 19:13:08 by dosong            #+#    #+#             */
/*   Updated: 2026/05/12 10:55:49 by dosong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t num, size_t size)
{
	void	*ptr;

	if (num == 0 || size == 0)
		return (malloc(0));
	if (__SIZE_MAX__ / size < num)
		return (NULL);
	ptr = malloc(num * size);
	if (!ptr)
		return (NULL);
	ft_memset(ptr, 0, num * size);
	return (ptr);
}
