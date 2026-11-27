/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haghomar <haghomar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 17:33:55 by haghomar          #+#    #+#             */
/*   Updated: 2026/11/27 16:08:45 by haghomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

static int nmb_len(unsigned long n)
{
	int cou;

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

static char *convert_base16(unsigned long x, char *base)
{
	char *hex;
	int i;
	int len;

	len = nmb_len(x);
	i = len - 1;
	hex = malloc((len + 1) * sizeof(char));
	if (!hex)
		return (NULL);
	if (x == 0)
		hex[0] = '0';
	while (x > 0)
	{
		hex[i] = base[x % 16];
		x /= 16;
		i--;
	}
	hex[len] = 0;
	return (hex);
}

int ft_print_hex(unsigned long x, char *base, char flag)
{
	char *hex;
	int sc;

	hex = NULL;
	sc = 0;
	if (flag == 'p')
	{
		hex = convert_base16(x, base);
		if (!hex)
			return (-1);
		sc+=write(1, "0x", 2);
		if (sc == -1)
		{
			free(hex);	
            return (-1);
		}
	}
	else if (flag == 'x' || flag == 'X')
		hex = convert_base16((unsigned int)x, base);
	if (!hex)
		return (-1);
	sc += ft_fd_putstr(hex, 1);
	free(hex);
	return (sc);
}

int ft_printx(va_list *arg, char *base, char flag)
{
	unsigned int x;

	x = va_arg(*arg, unsigned int);
	return (ft_print_hex((unsigned int)x, base, flag));
}
