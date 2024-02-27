/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gachalif <gachalif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 09:42:08 by gachalif          #+#    #+#             */
/*   Updated: 2024/02/13 09:42:08 by gachalif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
		ft_putchar_fd('-', fd);
	if (n > 9 || n < -9)
	{
		if (n < 0)
			ft_putnbr_fd((-(n / 10)), fd);
		else
			ft_putnbr_fd((n / 10), fd);
	}
	if (n < 0)
		ft_putchar_fd(-(n % 10) + 48, fd);
	else
		ft_putchar_fd((n % 10) + 48, fd);
}
