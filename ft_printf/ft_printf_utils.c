/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honam <honam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/30 13:44:17 by honam             #+#    #+#             */
/*   Updated: 2026/06/30 13:44:52 by honam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_char(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_printf_str(const char *str)
{
	int	len;

	len = 0;
	if (str == NULL)
	{
		if (write(1, "(null)", 6) == -1)
			return (-1);
		return (6);
	}
	while (str[len] != '\0')
	{
		if (write(1, &str[len], 1) == -1)
			return (-1);
		len++;
	}
	return (len);
}

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

int	ft_printf_hex(unsigned long long n, char type)
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
		temp = ft_printf_hex(n / 16, type);
		if (temp == -1)
			return (-1);
		len += temp;
	}
	idx = n % 16;
	if (write(1, &base[idx], 1) == -1)
		return (-1);
	len++;
	return (len);
}

int	ft_printf_ptr(void *p)
{
	int	len;
	int	temp;

	if (p == NULL)
	{
		if (write(1, "(nil)", 5) == -1)
			return (-1);
		return (5);
	}
	len = 0;
	if (write(1, "0x", 2) == -1)
		return (-1);
	len += 2;
	temp = ft_printf_hex((unsigned long long)p, 'x');
	if (temp == -1)
		return (-1);
	len += temp;
	return (len);
}
