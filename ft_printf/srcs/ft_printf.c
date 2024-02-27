/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gachalif <gachalif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 14:36:20 by gachalif          #+#    #+#             */
/*   Updated: 2024/02/15 22:08:53 by gachalif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_match_start(const char *s, char *start)
{
	while (*start)
	{
		if (*start != *s)
			return (0);
		start++;
		s++;
	}
	return (1);
}

static size_t	ft_put_arg(const char *s, va_list args, size_t *bank)
{
	if (ft_match_start(s, "%c"))
		*bank += ft_putchar(va_arg(args, int));
	else if (ft_match_start(s, "%s"))
		*bank += ft_putstr(va_arg(args, char *));
	else if (ft_match_start(s, "%p"))
		*bank += ft_putptr(va_arg(args, void *));
	else if (ft_match_start(s, "%d") || ft_match_start(s, "%i"))
		*bank += ft_putint(va_arg(args, int), 0);
	else if (ft_match_start(s, "%u"))
		*bank += ft_putuint(va_arg(args, unsigned int), 0);
	else if (ft_match_start(s, "%x"))
		*bank += ft_puthex(va_arg(args, unsigned int), 0, 0);
	else if (ft_match_start(s, "%X"))
		*bank += ft_puthex(va_arg(args, unsigned int), 0, 1);
	else if (ft_match_start(s, "%%"))
		*bank += ft_putchar('%');
	else
	{
		*bank += ft_putchar(*(s));
		return (1);
	}
	return (2);
}

int	ft_printf(const char *s, ...)
{
	va_list	args;
	size_t	bank;

	bank = 0;
	va_start(args, s);
	while (*s)
		s += ft_put_arg(s, args, &bank);
	return (bank);
}
