/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honam <honam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 15:15:34 by honam             #+#    #+#             */
/*   Updated: 2026/05/10 15:57:28 by honam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_count(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] == c && s[i] != '\0')
		i++;
	while (s[i] != '\0')
	{
		if (s[i] != c && s[i] != '\0')
		{
			count++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
		else
			i++;
	}
	return (count);
}

static char	*malloc_size(char const *s, char c, int *index)
{
	int		word_len;
	int		i;
	char	*sub_str;

	word_len = 0;
	while (s[*index] == c)
	{
		(*index)++;
	}
	while (s[*index] != c && s[*index] != '\0')
	{
		(*index)++;
		word_len++;
	}
	sub_str = (char *)malloc(word_len + 1);
	if (sub_str == NULL)
		return (NULL);
	sub_str[word_len] = '\0';
	i = 0;
	while (i < word_len)
	{
		sub_str[i] = s[(*index) - word_len + i];
		i++;
	}
	return (sub_str);
}

static void	all_free(char **s, size_t count)
{
	while (count--)
		free(s[count]);
	free(s);
}

char	**ft_split(char const *s, char c)
{
	size_t	count;
	size_t	i;
	int		index;
	char	**split_str;

	if (s == NULL)
		return (NULL);
	count = word_count(s, c);
	split_str = (char **)malloc((sizeof(char *)) * (count + 1));
	if (split_str == NULL)
		return (NULL);
	index = 0;
	i = 0;
	while (i < count)
	{
		split_str[i] = malloc_size(s, c, &index);
		if (split_str[i] == 0)
		{
			all_free(split_str, i);
			return (NULL);
		}
		i++;
	}
	split_str[i] = NULL;
	return (split_str);
}
