/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gachalif <gachalif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 09:40:18 by gachalif          #+#    #+#             */
/*   Updated: 2024/02/13 09:40:18 by gachalif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	if (!dest || !src)
		return (dest);
	while (n > 0)
	{
		((char *) dest)[n - 1] = ((char *) src)[n - 1];
		n--;
	}
	return (dest);
}
