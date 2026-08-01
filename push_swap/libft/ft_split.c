/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dosong <dosong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/10 17:55:36 by dosong            #+#    #+#             */
/*   Updated: 2026/05/06 16:56:25 by dosong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	free_all(char **ptr, int j)
{
	while (j >= 0)
		free(ptr[j--]);
	free(ptr);
}

static char	*word(char const *s, int start, int end)
{
	char	*result;
	int		i;

	i = 0;
	result = (char *)malloc(end - start + 1);
	if (!result)
		return (NULL);
	while (start < end)
		result[i++] = s[start++];
	result[i] = '\0';
	return (result);
}

static int	count_words(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			count++;
		i++;
	}
	return (count);
}

static void	fill_words(char const *s, char c, char **ptr)
{
	int	i;
	int	j;
	int	start;

	i = 0;
	j = 0;
	start = 0;
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			start = i;
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
		{
			ptr[j] = word(s, start, i + 1);
			if (!ptr[j])
			{
				free_all(ptr, j - 1);
				return ;
			}
			j++;
		}
		i++;
	}
	ptr[j] = NULL;
}

char	**ft_split(char const *s, char c)
{
	int		count;
	char	**ptr;

	if (!s)
		return (NULL);
	count = count_words(s, c);
	ptr = (char **)malloc(sizeof(char *) * (count + 1));
	if (!ptr)
		return (NULL);
	fill_words(s, c, ptr);
	return (ptr);
}
