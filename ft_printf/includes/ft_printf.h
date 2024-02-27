/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gachalif <gachalif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 14:36:28 by gachalif          #+#    #+#             */
/*   Updated: 2024/02/15 15:59:17 by gachalif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *s, ...);

size_t	ft_putchar(int c);
size_t	ft_putstr(char *s);
size_t	ft_putint(int n, size_t cnt);
size_t	ft_putuint(unsigned int n, size_t cnt);
size_t	ft_puthex(unsigned int n, size_t cnt, char is_upper);
size_t	ft_putptr(void *ptr);

#endif