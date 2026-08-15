/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dosong <dosong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 16:41:34 by dosong            #+#    #+#             */
/*   Updated: 2026/08/03 13:21:05 by dosong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *s, int fd)
{
	int	count;

	count = 0;
	if (!s)
	{
		count += ft_putstr("(null)", fd);
		return (count);
	}
	while (*s)
	{
		write(fd, s++, 1);
		count++;
	}
	return (count);
}
