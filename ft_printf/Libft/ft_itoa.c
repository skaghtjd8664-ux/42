/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honam <honam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 15:36:55 by honam             #+#    #+#             */
/*   Updated: 2026/05/10 16:18:08 by honam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	check_len(long long n)
{
	int	i;

	if (n == 0)
		return (1);
	if (n < 0)
		n *= -1;
	i = 0;
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	long long	num;
	int			count;
	char		*s;

	num = (long long)n;
	count = check_len(num);
	if (num < 0)
		count++;
	s = (char *)malloc(count + 1);
	if (s == NULL)
		return (NULL);
	s[count] = '\0';
	if (num < 0)
	{
		s[0] = '-';
		num *= -1;
	}
	if (num == 0)
		s[0] = '0';
	while (num > 0)
	{
		s[(count--) - 1] = num % 10 + '0';
		num = num / 10;
	}
	return (s);
}
