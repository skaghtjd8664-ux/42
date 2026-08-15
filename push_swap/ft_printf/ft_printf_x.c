/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dosong <dosong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 16:54:34 by dosong            #+#    #+#             */
/*   Updated: 2026/06/26 18:55:28 by dosong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_x(unsigned long long h, char c)
{
	char	*hex;
	int		count;

	count = 0;
	hex = "0123456789abcdef";
	if (c == 'X')
		hex = "0123456789ABCDEF";
	if (h >= 16)
		count += ft_printf_x((h / 16), c);
	write(1, &hex[h % 16], 1);
	count++;
	return (count);
}
