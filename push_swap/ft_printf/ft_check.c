/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dosong <dosong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 15:31:08 by dosong            #+#    #+#             */
/*   Updated: 2026/06/25 15:34:25 by dosong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	ft_check(char c)
{
	char	*specifier;
	int		i;

	i = 0;
	specifier = "cspdiuxX%";
	while (specifier[i])
	{
		if (c == specifier[i])
			return (c);
		i++;
	}
	return (0);
}
