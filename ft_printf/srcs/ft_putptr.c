/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gachalif <gachalif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 15:28:07 by gachalif          #+#    #+#             */
/*   Updated: 2024/02/15 21:23:55 by gachalif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	ft_get_hexchar(unsigned long n, char is_upper)
{
	if (is_upper)
		return ("0123456789ABCDEF"[n]);
	else
		return ("0123456789abcdef"[n]);
}

static size_t	ft_puthex_long(unsigned long n, size_t cnt, char is_upper)
{
	cnt = 0;
	if (n > 15)
		cnt += ft_puthex_long((n / 16), cnt, is_upper);
	cnt += ft_putchar(ft_get_hexchar(n % 16, is_upper));
	return (cnt);
}

size_t	ft_putptr(void *ptr)
{
	return (ft_putstr("0x") + ft_puthex_long((unsigned long)ptr, 0, 0));
}
