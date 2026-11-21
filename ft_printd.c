/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haghomar <haghomar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/21 16:00:44 by haghomar          #+#    #+#             */
/*   Updated: 2026/11/21 17:13:28 by haghomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "libft/libft.h"

void	ft_printd(va_list arg)
{
	int	d;

	d=0;
	d = va_arg(arg, int);
	// printf("len:%ld\n",ft_strlen(s1));
	// printf("arg:%s\n",s1);
	ft_putnbr_fd(d, 1);
}
