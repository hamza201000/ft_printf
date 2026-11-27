/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haghomar <haghomar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 21:38:20 by haghomar          #+#    #+#             */
/*   Updated: 2026/11/27 03:25:15 by haghomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_fd_putstr(char *s, int fd)
{
	int sc;

	sc = 0;
	if ((!s))
		return (-1);
	while (*s)
	{
		sc+=write(fd, s, 1);
		if (sc == -1)
            return (-1);
		s++;
	}
	return (sc);
}

static int	ft_fd_putnbr(unsigned int n, int fd)
{
	char	*nmb;
	int		sc;
	
	sc = 0;
	nmb = ft_itoa((long)n);
	if (!nmb)
		return (-1);
	sc = ft_fd_putstr(nmb, fd);
	free(nmb);
	return (sc);
}

int	ft_printu(va_list *arg)
{
	int				sc;
	unsigned int	u;

	sc = 0;
	u = va_arg(*arg, unsigned int);
	sc = ft_fd_putnbr(u, 1);
	return (sc);
}
