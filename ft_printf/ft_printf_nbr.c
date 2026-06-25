/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_nbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honam <honam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 12:16:30 by honam             #+#    #+#             */
/*   Updated: 2026/06/24 12:16:30 by honam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_int(int n)
{
	char	*str;
	int		len;

	str = ft_itoa(n);
	if (str == NULL)
		return (-1);
	len = ft_strlen(str);
	if (write(1, str, 1) == -1)
	{
		free(str);
		return (-1);
	}
	free(str);
	return (len);
}

int	ft_printf_unsigned(unsigned int n)
{
	int	len;
	int	ret;

	len = 0;
	if (n > 9)
	{
		ret = ft_printf_unsigned(n / 10);
		if (ret == -1)
			return (-1);
		len += ret;
	}
	if (write(1, &"0123456789"[n % 10], 1) == -1)
		return (-1);
	len++;
	return (len);
}
