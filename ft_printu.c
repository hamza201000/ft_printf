/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haghomar <haghomar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 21:38:20 by haghomar          #+#    #+#             */
/*   Updated: 2026/11/26 23:33:43 by haghomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	int	nmb_len(unsigned int n)
{
	int	cou;

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

static	int	ft_putnbr_fd(unsigned int n, int fd)
{
	char	*nmb;

	nmb = ft_itoa(n);
	if (!nmb)
		return (-1);
	ft_putstr_fd(nmb, fd);
	free(nmb);
}

int	ft_printu(va_list arg)
{
	int				len;
	unsigned int	u;

	len = 0;
	u = va_arg(arg, unsigned int);
	len = ft_putnbr_fd(u, 1);
	if (len == -1)
		return (-1);
	len = nmb_len(u);
	return (len);
}
