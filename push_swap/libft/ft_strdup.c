/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dosong <dosong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 19:38:18 by dosong            #+#    #+#             */
/*   Updated: 2026/04/11 17:02:32 by dosong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*cp_str;
	int		i;

	i = 0;
	cp_str = (char *)malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (!cp_str)
		return (NULL);
	while (src[i])
	{
		cp_str[i] = src[i];
		i++;
	}
	cp_str[i] = '\0';
	return (cp_str);
}
