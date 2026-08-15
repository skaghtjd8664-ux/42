/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dosong <dosong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 19:06:38 by dosong            #+#    #+#             */
/*   Updated: 2026/08/03 13:21:49 by dosong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *str, ...);
int		ft_mainprintf(char specifier, va_list var);
int		ft_putstr(char *s, int fd);
int		ft_putnbr(long long n, int fd);
int		ft_putchar(char c);
char	ft_check(char c);
int		ft_printf_x(unsigned long long h, char c);
int		ft_printf_p(void *ptr);
int		ft_printf_u(unsigned int num);

#endif