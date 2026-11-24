/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haghomar <haghomar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/21 16:00:44 by haghomar          #+#    #+#             */
/*   Updated: 2026/11/22 14:31:17 by haghomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "libft/libft.h"

static size_t	nmb_len(long n)
{
	size_t	cou;

	cou = 0;
	if (n < 0)
	{
		cou++;
		n *= -1;
	}
	else if (n == 0)
	{
		cou++;
	}
	while (n > 0)
	{
		n /= 10;
		cou++;
	}
	return (cou);
}

int	ft_printd(va_list arg)
{
	int	d;
	int len;
	
	d = va_arg(arg, int);
	// printf("len:%ld\n",ft_strlen(s1));
	// printf("arg:%s\n",s1);
	len = (int)nmb_len((long)d);
	ft_putnbr_fd(d, 1);
	return len;
}
