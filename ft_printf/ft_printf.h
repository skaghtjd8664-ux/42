/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: honam <honam@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 12:08:20 by honam             #+#    #+#             */
/*   Updated: 2026/06/24 12:08:20 by honam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdint.h>
# include "./libft/libft.h"

int	ft_printf(const char *format, ...);
int	ft_printf_char(char c);
int	ft_printf_str(const char *str);
int	ft_printf_ptr(void *p);
int	ft_printf_int(int n);
int	ft_printf_unsigned(unsigned int n);
int	ft_printf_hex(unsigned long long n, char type);

#endif
