/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gachalif <gachalif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 15:49:53 by gachalif          #+#    #+#             */
/*   Updated: 2024/02/13 16:28:40 by gachalif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	count_chars(int n)
{
	int	bank;

	bank = 1;
	if (n < 0)
		bank++;
	while (n > 9 || n < -9)
	{
		n /= 10;
		bank++;
	}
	return (bank);
}

static	void	ft_putnumber_in_str(char *s, int n)
{
	int	sign;

	sign = (2 * (n >= 0)) - 1;
	if (n > 9 || n < -9)
		ft_putnumber_in_str(s, n / 10);
	s[ft_strlen(s)] = (sign * (n % 10)) + 48;
}

char	*ft_itoa(int n)
{
	char	*re;
	int		sign;

	re = ft_calloc(1, (size_t)(sizeof(char) * (count_chars(n) + 1)));
	if (!re)
		return (NULL);
	sign = (2 * (n >= 0)) - 1;
	if (sign == -1)
		*re = '-';
	ft_putnumber_in_str(re, n);
	re[ft_strlen(re)] = 0;
	return (re);
}
