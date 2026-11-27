/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prints.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haghomar <haghomar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 23:56:47 by haghomar          #+#    #+#             */
/*   Updated: 2026/11/27 02:17:43 by haghomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_prints(va_list arg)
{
	char	*s1;
	int		len;
	int		sc;

	sc=0;
	s1 = va_arg(arg, char *);
	if (s1 == NULL)
	{
		sc+=write(1, "(null)", 6);
		if (sc == -1)
            return (-1);
		return (sc);
	}
	len = (int)ft_strlen(s1);
	sc += write(1, s1, len);
	if (sc == -1)
        return (-1);
	return (sc);
}
