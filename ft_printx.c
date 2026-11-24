/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haghomar <haghomar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 17:33:55 by haghomar          #+#    #+#             */
/*   Updated: 2026/11/24 19:41:57 by haghomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

static	size_t nmb_len(long n)
{
	size_t	cou;

	cou = 0;
	if (n == 0)
	{
		cou++;
	}
	while (n > 0)
	{
		n /= 16;
		cou++;
	}
	return (cou);
}

char	*convert_base16(unsigned long x,char *base)
{
	char	*hex;
	int		i;
	int		len;
	
	len = nmb_len(x);
	i = len-1;
	hex = malloc((len + 1) * sizeof(char));
	
	while (x > 0)
	{
		hex[i] = base[x % 16];
		x/=16;
		i--;
	}
	hex[len]=0;
	return hex;
}

int	ft_printx(va_list arg,char *base)
{
	unsigned long	x;
	char			*hex;

	x = va_arg(arg, unsigned long);
	hex = convert_base16(x, base);
	ft_putstr_fd(hex,1);
	return (int)ft_strlen(hex);
}
