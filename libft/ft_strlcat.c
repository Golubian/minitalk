/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gachalif <gachalif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 09:44:45 by gachalif          #+#    #+#             */
/*   Updated: 2024/02/13 09:44:45 by gachalif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

static int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

size_t	ft_strlcat(char *dst, char *src, size_t size)
{
	size_t	i;
	size_t	len;

	if (!src || !dst)
		return (0);
	len = ft_strlen(dst);
	if (size < len + 1)
		return (ft_strlen(src) + size);
	i = 0;
	while (i < (size - len) - 1 && src[i])
	{
		dst[i + len] = src[i];
		i++;
	}
	if (i < size)
		dst[i + len] = 0;
	return (len + ft_strlen(src));
}
