/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dosong <dosong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/11 11:56:43 by dosong            #+#    #+#             */
/*   Updated: 2026/04/11 13:47:55 by dosong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_digits(long n)
{
	int	count;

	count = 1;
	if (n < 0)
	{
		count++;
		n = -n;
	}
	while (n >= 10)
	{
		n /= 10;
		count++;
	}
	return (count);
}

static void	fill_result(char *result, long num, int len)
{
	if (num < 0)
	{
		result[0] = '-';
		num = -num;
		while (len-- > 1)
		{
			result[len] = '0' + (num % 10);
			num /= 10;
		}
	}
	else
	{
		while (len-- > 0)
		{
			result[len] = '0' + (num % 10);
			num /= 10;
		}
	}
}

char	*ft_itoa(int n)
{
	long	num;
	int		len;
	char	*result;

	num = (long)n;
	len = count_digits(num);
	result = (char *)malloc(len + 1);
	if (!result)
		return (0);
	result[len] = '\0';
	fill_result(result, num, len);
	return (result);
}
