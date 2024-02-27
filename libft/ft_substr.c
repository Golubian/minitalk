/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gachalif <gachalif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 09:46:03 by gachalif          #+#    #+#             */
/*   Updated: 2024/02/13 09:46:03 by gachalif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	i;
	size_t	st;

	if (!s)
		return ((void *) 0);
	if (len > (size_t) ft_strlen(s))
		len = ft_strlen(s);
	new = malloc(sizeof(char) * (len + 1));
	if (!new)
		return (NULL);
	i = 0;
	st = (size_t) start;
	while (i < len && (st + i) < (size_t)ft_strlen(s) && s[st + i])
	{
		new[i] = s[start + i];
		i++;
	}
	new[i] = 0;
	return (new);
}
