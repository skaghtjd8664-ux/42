/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dosong <dosong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 19:28:17 by dosong            #+#    #+#             */
/*   Updated: 2026/08/03 13:22:03 by dosong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_p(void *ptr)
{
	unsigned long long	addr;
	int					count;

	count = 0;
	if (!ptr)
	{
		count += ft_putstr("(nil)", 1);
		return (count);
	}
	addr = (unsigned long long )ptr;
	count += ft_putstr("0x", 1);
	count += ft_printf_x((unsigned long long )addr, 'x');
	return (count);
}
