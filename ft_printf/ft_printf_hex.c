/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honam <honam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/25 11:30:29 by honam             #+#    #+#             */
/*   Updated: 2026/06/25 12:36:25 by honam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_hex(unsigned int n, char type)
{
	int		len;
	char	*base;
	int		temp;
	int		idx;

	idx = 0;
	len = 0;
	if (type == 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	if (n > 15)
	{
		temp = ft_pritnf_hex(n / 16, type);
		if (temp == -1)
			return (-1);
		len += temp;
	}
	if (write(1, &base[idx], 1) == -1)
		return (-1);
	len++;
	return (len);
}

int	ft_printf_ptr(void *p)
{
	int	len;
	int	temp;

	len = 0;
	if (write(1, "0x", 2) == -1)
		return (-1);
	len += 2;
	temp = ft_printf_hex((unsigned long)p, 'x');
	if (temp == -1)
		return (-1);
	len += temp;
	return (len);
}
