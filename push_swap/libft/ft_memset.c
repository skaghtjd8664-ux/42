/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dosong <dosong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/05 16:17:50 by dosong            #+#    #+#             */
/*   Updated: 2026/04/05 18:06:50 by dosong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t size)
{
	unsigned char	*ptr;
	size_t			i;

	ptr = (unsigned char *)str;
	i = 0;
	while (i < size)
	{
		ptr[i] = (unsigned char)c;
		i++;
	}
	return (ptr);
}
