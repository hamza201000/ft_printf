/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haghomar <haghomar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/22 19:29:39 by haghomar          #+#    #+#             */
/*   Updated: 2026/11/26 23:02:02 by haghomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int	ft_printp(va_list arg)
{
	void	*x;
	int		len;

	len = 0;
	x = va_arg(arg, void *);
	if (x == 0)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	len += ft_print_hex((unsigned long)x, "0123456789abcdef", 'p');
	return (len);
}
