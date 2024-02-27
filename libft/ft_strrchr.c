/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gachalif <gachalif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 09:45:30 by gachalif          #+#    #+#             */
/*   Updated: 2024/02/13 09:45:30 by gachalif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_strrchr(const char *s, int c)
{
	int	len;

	if (!s)
		return ((void *) 0);
	len = ft_strlen((char *) s) + 1;
	if (len == 0)
		return ((void *) 0);
	while (len >= 1)
	{
		if (s[len - 1] == (char) c)
			return ((char *)(s + (len - 1)));
		len--;
	}
	if (*s == (char) c)
		return ((char *) s);
	return ((void *)(0));
}
