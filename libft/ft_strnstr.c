/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honam <honam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 17:59:38 by honam             #+#    #+#             */
/*   Updated: 2026/05/09 19:08:16 by honam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	littele_len;
	size_t	i;

	littele_len = ft_strlen(little);
	if (littele_len == 0)
		return ((char *)big);
	else if (littele_len > len)
		return (NULL);
	i = 0;
	while (*big != '\0' && len >= i + littele_len)
	{
		if (ft_strncmp(big, little, littele_len) == 0)
			return ((char *)big);
		big++;
		i++;
	}
	return (NULL);
}
