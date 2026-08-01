/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dosong <dosong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 16:21:31 by dosong            #+#    #+#             */
/*   Updated: 2026/04/07 17:19:19 by dosong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *substr, size_t len)
{
	size_t	i;
	size_t	temp;

	i = 0;
	if (*substr == '\0')
		return ((char *)str);
	while (str[i] && i < len)
	{
		temp = 0;
		if (str[i] == substr[temp])
		{
			while (substr[temp] && str[i + temp])
			{
				if (substr[temp] != str[i + temp] || (i + temp) >= len)
					break ;
				temp++;
			}
			if (substr[temp] == '\0')
				return ((char *)&str[i]);
		}
		i++;
	}
	return (0);
}
