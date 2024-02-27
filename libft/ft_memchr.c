/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gachalif <gachalif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 09:39:40 by gachalif          #+#    #+#             */
/*   Updated: 2024/02/13 09:39:40 by gachalif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	size_t			i;

	if (!s || n == 0)
		return ((void *) 0);
	str = (unsigned char *) s;
	i = 0;
	while (str && str[i] != (unsigned char) c && i < (n - 1))
		i++;
	if (str[i] == (unsigned char) c)
		return ((void *)(str + i));
	else
		return ((void *) 0);
}
