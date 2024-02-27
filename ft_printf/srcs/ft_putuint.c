/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gachalif <gachalif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 15:12:07 by gachalif          #+#    #+#             */
/*   Updated: 2024/02/15 15:12:56 by gachalif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_putuint(unsigned int n, size_t cnt)
{
	if (n > 9)
		cnt += ft_putint(n / 10, cnt);
	cnt += ft_putchar((n % 10) + 48);
	return (cnt);
}
