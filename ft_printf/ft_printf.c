/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honam <honam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 12:20:28 by honam             #+#    #+#             */
/*   Updated: 2026/06/25 12:07:05 by honam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	parse_format(const char type, va_list ap)
{
	int	len;

	len = 0;
	if (type == 'c')
		len = ft_printf_char(va_arg(ap, int));
	else if (type == 's')
		len = ft_printf_str(va_arg(ap, char *));
	else if (type == 'p')
		len = ft_printf_ptr(va_arg(ap, void *));
	else if (type == 'd' || type == 'i')
		len = ft_printf_int(va_arg(ap, int));
	else if (type == 'u')
		len = ft_printf_unsigned(va_arg(ap, unsigned int));
	else if (type == 'x' || type == 'X')
		len = ft_printf_hex(va_arg(ap, unsigned int), type);
	else if (type == '%')
		len = ft_printf_char('%');
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		result;
	int		len;

	len = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '\0')
				break ;
			result = parse_format(*format, ap);
		}
		else
			result = write(1, format, 1);
		if (result == -1)
			return (-1);
		len += result;
		format++;
	}
	va_end(ap);
	return (len);
}
