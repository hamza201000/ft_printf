/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haghomar <haghomar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/21 16:00:44 by haghomar          #+#    #+#             */
/*   Updated: 2026/11/26 22:55:15 by haghomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

static	size_t	nmb_len(long n)
{
	size_t	cou;

	cou = 0;
	if (n < 0)
	{
		cou++;
		n *= -1;
	}
	else if (n == 0)
	{
		cou++;
	}
	while (n > 0)
	{
		n /= 10;
		cou++;
	}
	return (cou);
}

int	ft_printd(va_list arg)
{
	int	d;
	int	len;

	d = va_arg(arg, int);
	len = (int)nmb_len((long)d);
	ft_putnbr_fd(d, 1);
	return (len);
}
