/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haghomar <haghomar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/19 16:52:42 by haghomar          #+#    #+#             */
/*   Updated: 2026/11/27 01:02:48 by haghomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_check_format(char c, va_list args)
{
	if (c == 'c')
		return (ft_printc(args));
	else if (c == 's')
		return (ft_prints(args));
	else if (c == 'd' || c == 'i')
		return (ft_printd(args));
	else if (c == 'p')
		return (ft_printp(args));
	else if (c == 'x')
		return (ft_printx(args, "0123456789abcdef", 'x'));
	else if (c == 'X')
		return (ft_printx(args, "0123456789ABCDEF", 'X'));
	else if (c == 'u')
		return (ft_printu(args));
	return (0);
}

static int	ft_handle_percent(const char *s, int *i, va_list args)
{
	if (s[*i + 1] == '%')
	{
		write(1, "%", 1);
		(*i)++;
		return (1);
	}
	(*i)++;
	return (ft_check_format(s[*i], args));
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		count;
	int		i;
	int		res;
	
	va_start(args, s);
	count = 0;
	i = 0;
	res = 0;
	if (!s)
		return (-1);
	while (s[i])
	{
		if (s[i] == '%' && s[i + 1])
		{
			res = ft_handle_percent(s, &i, args);
			if (res < 0)
			{
				va_end(args);
				return (-1);
			}
			count += res;
		}
		else
			count+=write(1, &s[i], 1);
		i++;
	}
	va_end(args);
	return (count);
}
