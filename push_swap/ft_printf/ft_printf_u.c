/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dosong <dosong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/23 01:11:14 by dosong            #+#    #+#             */
/*   Updated: 2026/06/23 01:14:02 by dosong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_u(unsigned int num)
{
	int	count;

	count = 0;
	if (num >= 10)
		count += ft_printf_u(num / 10);
	write(1, &"0123456789"[num % 10], 1);
	count++;
	return (count);
}
