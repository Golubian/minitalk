/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gachalif <gachalif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 09:35:19 by gachalif          #+#    #+#             */
/*   Updated: 2024/02/13 09:35:19 by gachalif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memset(void *s, int c, size_t n)
{
	if (!s)
		return ((void *) 0);
	while (n > 0)
	{
		((char *) s)[n - 1] = c;
		n--;
	}
	return (s);
}