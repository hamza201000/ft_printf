/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haghomar <haghomar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 21:38:20 by haghomar          #+#    #+#             */
/*   Updated: 2026/11/26 03:22:26 by haghomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

static	void	ft_putnbr_fd2(unsigned int n, int fd)
{
	char	*nmb;

	nmb = ft_itoa(n);
	ft_putstr_fd(nmb, fd);
	free(nmb);
}

int	ft_printu(va_list arg)
{
	int				len;
	unsigned int	u;

	u = va_arg(arg, unsigned int);
	len = (int)nmb_len((long)u);
	ft_putnbr_fd2(u, 1);
	return (len);
}
