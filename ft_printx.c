/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haghomar <haghomar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 17:33:55 by haghomar          #+#    #+#             */
/*   Updated: 2026/11/26 23:36:20 by haghomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

static int	nmb_len(unsigned long n)
{
	int	cou;

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

static	char	*convert_base16(unsigned long x, char *base)
{
	char	*hex;
	int		i;
	int		len;

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

int	ft_print_hex(unsigned long x, char *base, char flag)
{
	char	*hex;
	int		len;

	hex = NULL;
	len = 0;
	if (flag == 'p')
	{
		write(1, "0x", 2);
		len += 2;
		hex = convert_base16(x, base);
	}
	else if (flag == 'x' || flag == 'X')
		hex = convert_base16((unsigned int)x, base);
	if (!hex)
		return (-1);
	ft_putstr_fd(hex, 1);
	len += (int)ft_strlen(hex);
	free(hex);
	return (len);
}

int	ft_printx(va_list arg, char *base, char flag)
{
	unsigned int	x;
	char			*hex;
	int				len;

	hex = NULL;
	len = 0;
	x = va_arg(arg, unsigned int);
	len = ft_print_hex((unsigned int)x, base, flag);
	return (len);
}
