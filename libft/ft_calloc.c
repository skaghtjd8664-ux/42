/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honam <honam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 17:59:38 by honam             #+#    #+#             */
/*   Updated: 2026/06/06 11:15:45 by honam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr_void;
	char	*ptr_char;
	size_t	i;

	ptr_void = (void *)malloc(size * count);
	if (ptr_void == NULL)
		return (NULL);
	ptr_char = (char *)ptr_void;
	i = 0;
	while (i < count * size)
	{
		ptr_char[i] = 0;
		i++;
	}
	return (ptr_void);
}
