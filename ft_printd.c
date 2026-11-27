/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haghomar <haghomar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/21 16:00:44 by haghomar          #+#    #+#             */
/*   Updated: 2026/11/27 17:24:32 by haghomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_fd_putnbr(int n, int fd)
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

int	ft_printd(va_list *arg)
{
	int	d;

	d = va_arg(*arg, int);
	return (ft_fd_putnbr(d, 1));
}
