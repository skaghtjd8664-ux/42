/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dosong <dosong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 18:22:55 by dosong            #+#    #+#             */
/*   Updated: 2026/05/12 11:02:52 by dosong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (0);
	ptr = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1));
	if (ptr == 0)
		return (0);
	while (i < (int)(ft_strlen(s1) + ft_strlen(s2)))
	{
		if (i < (int)ft_strlen((char *)s1))
			ptr[i] = s1[i];
		else
		{
			ptr[i] = s2[j];
			j++;
		}
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
