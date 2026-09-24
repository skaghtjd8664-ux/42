/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: honam <honam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/04 14:22:30 by honam             #+#    #+#             */
/*   Updated: 2026/07/15 17:37:15 by honam            ###   ########.fr       */
=======
/*   By: dosong <dosong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
<<<<<<<< HEAD:push_swap/libft/ft_strjoin.c
/*   Created: 2026/04/09 18:22:55 by dosong            #+#    #+#             */
/*   Updated: 2026/05/12 11:02:52 by dosong           ###   ########.fr       */
========
/*   Created: 2026/07/04 14:22:30 by honam             #+#    #+#             */
/*   Updated: 2026/07/16 09:14:18 by honam            ###   ########.fr       */
>>>>>>>> cf50b79 (finish py02):get_next_line/get_next_line_utils.c
>>>>>>> cf50b79 (finish py02)
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	int	count;

	count = 0;
	while (str[count] != '\0')
	{
		count++;
	}
	return (count);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (NULL);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	src_len;

	src_len = 0;
	while (src[src_len] != '\0')
	{
		src_len++;
	}
	if (size == 0)
	{
		return (src_len);
	}
	i = 0;
	while (src[i] && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_len);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
<<<<<<< HEAD
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
=======
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
>>>>>>> cf50b79 (finish py02)
}

char	*ft_strdup(const char *s1)
{
	int		i;
	int		size;
	char	*dup;

	size = ft_strlen(s1);
	dup = (char *)malloc(size + 1);
	if (dup == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		dup[i] = s1[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}
