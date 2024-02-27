/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gachalif <gachalif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 09:35:37 by gachalif          #+#    #+#             */
/*   Updated: 2024/02/13 09:35:37 by gachalif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>

static void	ft_bzero(void *s, size_t n)
{
	while (n > 0 && s)
	{
		((char *) s)[n - 1] = 0;
		n--;
	}
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*re;

	re = malloc(nmemb * size);
	if (!re)
		return (NULL);
	ft_bzero(re, nmemb * size);
	return (re);
}
