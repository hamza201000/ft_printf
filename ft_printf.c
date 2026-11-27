/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haghomar <haghomar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/19 16:52:42 by haghomar          #+#    #+#             */
/*   Updated: 2026/11/27 03:24:06 by haghomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_check_format(char c, va_list *args)
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

static int	ft_handle_percent(const char *s, int *i, va_list *args)
{
	if (s[*i + 1] == '%')
	{
		(*i)++;
		return (write(1, "%", 1));
	}
	(*i)++;
	return (ft_check_format(s[*i], args));
}

static int	ft_process(const char *s, int *i, va_list *args)
{
	if (s[*i] == '%' && s[*i + 1])
		return (ft_handle_percent(s, i, args));
	return (write(1, &s[*i], 1));
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		count;
	int		i;
	int		res;

	if (!s)
		return (-1);
	va_start(args, s);
	count = 0;
	i = 0;
	while (s[i])
	{
		res = ft_process(s, &i, &args);
		if (res < 0)
		{
			va_end(args);
			return (-1);
		}
		count += res;
		i++;
	}
	va_end(args);
	return (count);
}
