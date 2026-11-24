/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haghomar <haghomar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/22 19:29:39 by haghomar          #+#    #+#             */
/*   Updated: 2026/11/24 19:47:22 by haghomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int ft_printp(va_list arg)
{
	int len;
	// unsigned long ptr;

	len=0;
	// ptr = va_arg(arg, unsigned long);
	// convert_base16(ptr,"0123456789abcdef");
	ft_printx(arg,"0123456789abcdef");
	return len;
}
