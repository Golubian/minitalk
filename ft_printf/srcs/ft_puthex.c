/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gachalif <gachalif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 15:19:48 by gachalif          #+#    #+#             */
/*   Updated: 2024/02/15 22:07:48 by gachalif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	ft_get_hexchar(unsigned int n, char is_upper)
{
	if (is_upper)
		return ("0123456789ABCDEF"[n]);
	else
		return ("0123456789abcdef"[n]);
}

size_t	ft_puthex(unsigned int n, size_t cnt, char is_upper)
{
	cnt = 0;
	if (n > 15)
		cnt += ft_puthex(n / 16, cnt, is_upper);
	cnt += ft_putchar(ft_get_hexchar(n % 16, is_upper));
	return (cnt);
}
