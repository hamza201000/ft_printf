/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haghomar <haghomar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 21:38:20 by haghomar          #+#    #+#             */
/*   Updated: 2026/11/27 16:09:05 by haghomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_fd_putstr(char *s, int fd)
{
	int sc;

	sc = 0;
	if ((!s))
		return (-1);
	sc = write(fd, s, ft_strlen(s));
	if (sc == -1)
		return (-1);
	return (sc);
}

static int ft_fd_putnbr(unsigned int n, int fd)
{
	char *nmb;
	int sc;

	sc = 0;
	nmb = ft_itoa((long)n);
	if (!nmb)
		return (-1);
	sc = ft_fd_putstr(nmb, fd);
	free(nmb);
	return (sc);
}

int ft_printu(va_list *arg)
{
	unsigned int u;

	u = va_arg(*arg, unsigned int);
	return (ft_fd_putnbr(u, 1));
}
