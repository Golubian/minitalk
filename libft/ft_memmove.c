/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gachalif <gachalif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 09:40:23 by gachalif          #+#    #+#             */
/*   Updated: 2024/02/13 09:40:23 by gachalif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (!dest || !src)
		return ((void *) 0);
	i = 0;
	if (dest < src)
	{
		while (i < n)
		{
			((char *) dest)[i] = ((char *) src)[i];
			i++;
		}
	}
	else
	{
		while (n > 0)
		{
			((char *) dest)[n - 1] = ((char *) src)[n - 1];
			n--;
		}
	}
	return (dest);
}
