/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gachalif <gachalif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 15:14:04 by gachalif          #+#    #+#             */
/*   Updated: 2024/02/13 17:20:29 by gachalif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_strlen(const char	*str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static char	*ft_strdup_until(const char *src, char c)
{
	char	*new;
	int		i;
	int		len;

	if (!src)
		return (NULL);
	len = 0;
	while (src[len] && (src[len] != c))
		len++;
	new = (char *) malloc(sizeof(char) * (len + 2));
	if (!new)
		return (NULL);
	i = 0;
	while (i != len)
	{
		new[i] = src[i];
		i++;
	}
	new[i] = 0;
	return (new);
}

static int	ft_count_words(const char *str, char separator)
{
	int	i;
	int	last_space;
	int	count;

	if (!str)
		return (0);
	last_space = -1;
	i = 0;
	count = 0;
	while (str[i] != 0)
	{
		if (str[i] == separator)
		{
			last_space = i;
			i++;
			continue ;
		}
		else
			if (last_space == i - 1)
				count += 1;
		i++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**re;
	int		i;
	int		re_i;

	re = malloc(sizeof(char *) * (ft_count_words(s, c) + 1));
	if (!re)
		return (NULL);
	re[ft_count_words(s, c)] = 0;
	if (ft_count_words(s, c) == 0)
		return (re);
	re_i = 0;
	i = 0;
	while (s && s[i] != 0)
	{
		if (s[i] == c)
			i++;
		else
		{
			re[re_i] = ft_strdup_until(&s[i], c);
			i += ft_strlen(re[re_i]);
			re_i++;
		}
	}
	return (re);
}
