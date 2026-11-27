/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haghomar <haghomar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/22 19:29:39 by haghomar          #+#    #+#             */
/*   Updated: 2026/11/27 16:08:21 by haghomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int	ft_printp(va_list *arg)
{
	void	*x;

	x = va_arg(*arg, void *);
	if (x == NULL)
		return (write(1, "(nil)", 5));
	return (ft_print_hex((unsigned long)x, "0123456789abcdef", 'p'));
}
