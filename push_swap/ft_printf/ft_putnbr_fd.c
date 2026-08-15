/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dosong <dosong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 16:47:16 by dosong            #+#    #+#             */
/*   Updated: 2026/08/03 13:21:14 by dosong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(long long num, int fd)
{
	int			count;

	count = 0;
	if (num < 0)
	{
		write(fd, "-", 1);
		num = -num;
		count++;
	}
	if (num >= 10)
		count += ft_putnbr((num / 10), fd);
	write(fd, &"0123456789"[num % 10], 1);
	count++;
	return (count);
}
