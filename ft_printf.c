/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haghomar <haghomar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/19 16:52:42 by haghomar          #+#    #+#             */
/*   Updated: 2026/11/21 19:14:54 by haghomar         ###   ########.fr       */
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
	// int count;
	int s1;
	int i;

	va_start(args, s);
	i = 0;
	// count = sum(s);
	// printf("count:%d\n", count);
	while (s[i] != '\0')
	{
		// printf("i:%d\n",i);
		if (s[i] == '%' && s[i + 1] == 'c')
		{
			ft_printc(args);
			i++;
		}
		else if (s[i] == '%' && (s[i + 1] == 's'))
		{
			ft_prints(args);
			i++;
		}
		else if (s[i] == '%' && (s[i + 1] == 'd'))
		{
			ft_printd(args);
			i++;
		}
		else
			write(1, &s[i], 1);
		i++;
	}
	va_end(args);
	return 1;
}
