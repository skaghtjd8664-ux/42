/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dosong <dosong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 14:13:22 by dosong            #+#    #+#             */
/*   Updated: 2026/05/10 22:15:23 by dosong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int val)
{
	unsigned char	*ptr;
	unsigned char	v;
	int				i;

	i = (int)ft_strlen((char *)str);
	ptr = (unsigned char *)str;
	v = (unsigned char)val;
	while (i >= 0)
	{
		if (ptr[i] == v)
			return ((char *)&ptr[i]);
		i--;
	}
	return (0);
}
