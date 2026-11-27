/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haghomar <haghomar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/22 19:29:39 by haghomar          #+#    #+#             */
/*   Updated: 2026/11/27 02:39:00 by haghomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int	ft_printp(va_list arg)
{
	void	*x;
	int		sc;

	sc = 0;
	x = va_arg(arg, void *);
	if (x == NULL)
	{
		sc += write(1, "(nil)", 5);
		if (sc == -1)
            return (-1);
		return (sc);
	}
	sc += ft_print_hex((unsigned long)x, "0123456789abcdef", 'p');
	return (sc);
}
