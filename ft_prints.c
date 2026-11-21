/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prints.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haghomar <haghomar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 23:56:47 by haghomar          #+#    #+#             */
/*   Updated: 2026/11/21 17:05:37 by haghomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_prints(va_list arg)
{
	char	*s1;

	s1 = va_arg(arg, char *);
	ft_strlen(s1);
	// printf("len:%ld\n",ft_strlen(s1));
	// printf("arg:%s\n",s1);
	write(1, s1, ft_strlen(s1));
}