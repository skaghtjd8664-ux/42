/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dosong <dosong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/05 18:13:03 by dosong            #+#    #+#             */
/*   Updated: 2026/04/10 21:17:32 by dosong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *source, size_t num)
{
	unsigned char	*ptr1;
	unsigned char	*ptr2;
	size_t			i;

	if (!dest && !source)
		return (NULL);
	ptr1 = (unsigned char *)dest;
	ptr2 = (unsigned char *)source;
	i = 0;
	while (i < num)
	{
		ptr1[i] = ptr2[i];
		i++;
	}
	return (dest);
}
