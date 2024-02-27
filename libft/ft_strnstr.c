/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gachalif <gachalif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 09:45:20 by gachalif          #+#    #+#             */
/*   Updated: 2024/02/13 09:45:20 by gachalif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t	i;
	size_t	j;

	if (!haystack || !needle)
		return (0);
	if (ft_strlen(haystack) < ft_strlen(needle))
		return (0);
	if (!*needle)
		return ((char *)haystack);
	i = 0;
	while (*haystack && i < n)
	{
		j = 0;
		while (needle[j] == haystack[i + j] && needle[j] && (i + j) < n)
			j++;
		if (needle[j] == 0)
			return ((char *)(haystack + i));
		i++;
	}
	return (0);
}
