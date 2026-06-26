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
	long	num;
	int		len;
	int		ret;

	len = 0;
	if (n < 0)
	{
		if (write(1, "-", 1) == -1)
			return (-1);
		len++;
		n = -n;
	}
	num = (n % 10) + '0';
	if (n > 9)
	{
		ret = ft_printf_int(n / 10);
		if (ret == -1)
			return (-1);
		len += ret;
	}
	if (write(1, &num, 1) == -1)
		return (-1);
	len++;
	return (len);
}

int	ft_printf_unsigned(unsigned int n)
{
	int		len;
	int		ret;
	char	*base;

	len = 0;
	base = "0123456789";
	if (n > 9)
	{
		ret = ft_printf_unsigned(n / 10);
		if (ret == -1)
			return (-1);
		len += ret;
	}
	if (write(1, &base[n % 10], 1) == -1)
		return (-1);
	len++;
	return (len);
}
