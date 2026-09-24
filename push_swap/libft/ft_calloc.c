/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dosong <dosong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
<<<<<<<< HEAD:push_swap/libft/ft_calloc.c
/*   Created: 2026/04/07 19:13:08 by dosong            #+#    #+#             */
/*   Updated: 2026/05/12 10:55:49 by dosong           ###   ########.fr       */
========
/*   Created: 2026/06/30 13:35:03 by honam             #+#    #+#             */
/*   Updated: 2026/07/16 09:13:17 by honam            ###   ########.fr       */
>>>>>>>> cf50b79 (finish py02):get_next_line/get_next_line.h
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

<<<<<<<< HEAD:push_swap/libft/ft_calloc.c
void	*ft_calloc(size_t num, size_t size)
{
	void	*ptr;

	if (num == 0 || size == 0)
		return (malloc(0));
	if (__SIZE_MAX__ / size < num)
		return (NULL);
	ptr = malloc(num * size);
	if (!ptr)
		return (NULL);
	ft_memset(ptr, 0, num * size);
	return (ptr);
}
========
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

char	*get_next_line(int fd);
size_t	ft_strlen(const char *str);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s1);
#endif
>>>>>>>> cf50b79 (finish py02):get_next_line/get_next_line.h
