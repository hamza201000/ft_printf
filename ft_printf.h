/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haghomar <haghomar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/19 16:48:38 by haghomar          #+#    #+#             */
/*   Updated: 2026/11/24 17:12:31 by haghomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdarg.h>
#include <unistd.h>
#include "libft/libft.h"
#include <stdio.h>

int	ft_printf(const char *s, ...);
int	ft_prints(va_list arg);
int	ft_printd(va_list arg);
int	ft_printc(va_list arg);
int	ft_printx(va_list arg, char *base);
int	ft_printp(va_list arg);
int	ft_printu(va_list arg);
char	*convert_base16(unsigned long x,char *base);

#endif