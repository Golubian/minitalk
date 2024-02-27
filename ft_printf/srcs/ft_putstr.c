/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gachalif <gachalif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 15:03:22 by gachalif          #+#    #+#             */
/*   Updated: 2024/02/15 21:02:37 by gachalif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_putstr(char *s)
{
	size_t	bank;

	if (!s)
		return (ft_putstr("(null)"), 6);
	bank = 0;
	while (s && s[bank])
		bank++;
	write(1, s, bank);
	return (bank);
}
