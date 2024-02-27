/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gachalif <gachalif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 14:05:02 by gachalif          #+#    #+#             */
/*   Updated: 2024/02/13 14:33:47 by gachalif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	char_in_set(char c, char const *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		else
			set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*sstart;
	char	*send;
	char	*new;

	if (!s1 || !set)
		return (NULL);
	sstart = (char *)s1;
	send = (char *)s1 + ft_strlen(s1) - 1;
	while (char_in_set(sstart[0], set) == 1 && sstart[0] != 0)
		sstart++;
	while (char_in_set(send[0], set) == 1 && send[0] != 0)
		send--;
	new = ft_substr(sstart, 0, send - sstart + 1);
	if (!new)
		return (ft_strdup(""));
	else
		return (new);
}
