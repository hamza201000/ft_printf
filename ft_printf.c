/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haghomar <haghomar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/19 16:52:42 by haghomar          #+#    #+#             */
/*   Updated: 2026/11/24 17:05:53 by haghomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

// int sum(const char *s)
// {
// 	int count;

// 	count = 0;
// 	while (*s)
// 	{
// 		if (*s == '%')
// 			count++;
// 		s++;
// 	}
// 	return count;
// }

int ft_printf(const char *s, ...)
{
	va_list args;
	 int count;
	int i;

	va_start(args, s);
	i = 0;
	count=0;
	// count = sum(s);
	// printf("count:%d\n", count);
	while (s[i] != '\0')
	{
		// printf("i:%d\n",i);
		if (s[i] == '%' && s[i + 1] == 'c')
		{
			count+=ft_printc(args);
			i++;
		}
		else if (s[i] == '%' && (s[i + 1] == 's'))
		{
			count+=ft_prints(args);
			i++;
		}
		else if (s[i] == '%' && (s[i + 1] == 'd'))
		{
			count+=ft_printd(args);
			i++;
		}
		else if (s[i] == '%' && (s[i + 1] == 'p'))
		{
			count+=ft_printp(args);
			i++;
		}
		else if (s[i] == '%' && (s[i + 1] == 'x'))
		{
			count+=ft_printx(args,"0123456789abcdef");
			i++;
		}else if (s[i] == '%' && (s[i + 1] == 'X'))
		{
			count+=ft_printx(args,"0123456789ABCDEF");
			i++;
		}else if (s[i] == '%' && (s[i + 1] == 'u'))
		{
			count+=ft_printu(args);
			i++;
		}
		else if (s[i] == '%' && (s[i + 1] == 'i'))
		{
			count+=ft_printd(args);
			i++;
		}
		else
		{
			write(1, &s[i], 1);
			count++;
		}
		i++;
	}
	va_end(args);
	return count;
}


