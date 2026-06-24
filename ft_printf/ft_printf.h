/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 11:01:56 by marvin            #+#    #+#             */
/*   Updated: 2026/06/20 11:01:56 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	ft_printf_char(char c); //char %c
int	ft_printf_str(char *str); //char %s
int	ft_printf_ptr(void *p); //hex %p
int	ft_printf_int(int n); //nbr %d, %i
int	ft_printf_unsigned(unsigned int n); //nbr %u
int	ft_printf_hex(unsigned int n); //hex %x
int	ft_printf_hex_upper(unsigned int n); //hex %X
int	ft_printf_percent(void); //char %%

#endif
