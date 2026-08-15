/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dosong <dosong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 18:50:54 by dosong            #+#    #+#             */
/*   Updated: 2026/08/03 13:21:42 by dosong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_mainprintf(char specifier, va_list var)
{
	int	byte;

	byte = 0;
	if (specifier == 'c')
		byte = ft_putchar(va_arg(var, int));
	else if (specifier == 's')
		byte = ft_putstr(va_arg(var, char *), 1);
	else if (specifier == 'p')
		byte = ft_printf_p(va_arg(var, void *));
	else if (specifier == 'd' || specifier == 'i')
		byte = ft_putnbr(va_arg(var, int), 1);
	else if (specifier == 'u')
		byte = ft_printf_u(va_arg(var, unsigned int));
	else if (specifier == 'x' || specifier == 'X')
		byte = ft_printf_x(va_arg(var, unsigned int), specifier);
	else if (specifier == '%')
		byte = ft_putchar('%');
	return (byte);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		count;
	va_list	args;

	va_start(args, str);
	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '%' && ft_check(str[i + 1]))
		{
			count += ft_mainprintf(str[i + 1], args);
			i++;
		}
		else if (str[i] == '%' && str[i + 1] == '\0')
		{
			va_end(args);
			return (-1);
		}
		else
			count += ft_putchar(str[i]);
		i++;
	}
	va_end(args);
	return (count);
}
