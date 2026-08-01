/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dosong <dosong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 17:31:17 by dosong            #+#    #+#             */
/*   Updated: 2026/04/10 21:51:41 by dosong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned char	*dest;
	size_t			slen;
	size_t			i;
	size_t			j;

	slen = ft_strlen((char *)s);
	if (start >= (unsigned int)slen)
		len = 0;
	else if (len > slen - start)
		len = slen - start;
	dest = (unsigned char *)malloc(len + 1);
	if (!dest)
		return (NULL);
	i = (size_t)start;
	j = 0;
	while (j < len)
		dest[j++] = ((unsigned char *)s)[i++];
	dest[j] = '\0';
	return ((char *)dest);
}
