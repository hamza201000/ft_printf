/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prints.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haghomar <haghomar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 23:56:47 by haghomar          #+#    #+#             */
/*   Updated: 2026/11/27 16:06:33 by haghomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_prints(va_list *arg)
{
	char	*s1;
	int		len;

	s1 = va_arg(*arg, char *);
	if (s1 == NULL)
		return (write(1, "(null)", 6));
	len = (int)ft_strlen(s1);
	return (write(1, s1, len));
}
