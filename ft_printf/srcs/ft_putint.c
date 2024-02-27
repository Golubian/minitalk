/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gachalif <gachalif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 15:05:53 by gachalif          #+#    #+#             */
/*   Updated: 2024/02/15 22:06:20 by gachalif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_putint(int n, size_t cnt)
{
	int	was_neg;

	was_neg = 0;
	if (n < 0)
		was_neg = ft_putchar('-');
	if (n > 9 || n < -9)
	{
		if (n < 0)
			cnt += ft_putint(n / -10, cnt);
		else
			cnt += ft_putint(n / 10, cnt);
	}
	if (n < 0)
		cnt += ft_putchar(((n % 10) * -1) + 48);
	else
		cnt += ft_putchar((n % 10) + 48);
	return (cnt + was_neg);
}
