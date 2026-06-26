/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honam <honam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 14:12:27 by honam             #+#    #+#             */
/*   Updated: 2026/05/10 14:32:43 by honam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*new_str;
	unsigned int	s1_len;
	unsigned int	s2_len;
	unsigned int	str_len;
	unsigned int	i;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	str_len = s1_len + s2_len;
	new_str = (char *)malloc(str_len + 1);
	if (!new_str)
		return (NULL);
	i = 0;
	while (*s1 != '\0')
		new_str[i++] = *s1++;
	while (*s2 != '\0')
		new_str[i++] = *s2++;
	new_str[i] = '\0';
	return (new_str);
}
