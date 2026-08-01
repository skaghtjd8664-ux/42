/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dosong <dosong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 18:56:56 by dosong            #+#    #+#             */
/*   Updated: 2026/05/10 21:07:59 by dosong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_empty(void)
{
	char	*ptr;

	ptr = (char *)malloc(1);
	if (ptr)
		ptr[0] = '\0';
	return (ptr);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	i;
	char	*ptr;

	if (!s1 || s1[0] == '\0')
		return (ft_empty());
	i = 0;
	start = 0;
	end = ft_strlen((char *)s1) - 1;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	while (ft_strchr(set, s1[end]) && end > 0)
		end--;
	if (start > end)
		return (ft_empty());
	ptr = (char *)malloc(end - start + 2);
	if (!ptr)
		return (NULL);
	while (start <= end)
		ptr[i++] = s1[start++];
	ptr[i] = '\0';
	return (ptr);
}
