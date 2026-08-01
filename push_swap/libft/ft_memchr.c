/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dosong <dosong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 13:28:02 by dosong            #+#    #+#             */
/*   Updated: 2026/04/07 13:48:02 by dosong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *ptr, int value, size_t num)
{
	unsigned char	*str;
	unsigned char	v;
	size_t			i;

	str = (unsigned char *)ptr;
	v = (unsigned char)value;
	i = 0;
	while (i < num)
	{
		if (str[i] == v)
			return (&str[i]);
		i++;
	}
	return (0);
}
