/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gachalif <gachalif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 14:51:59 by gachalif          #+#    #+#             */
/*   Updated: 2024/02/27 08:43:40 by gachalif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	g_kill;

void	*ft_calloc(size_t nmemb, size_t size);

void	ft_putstr(unsigned char *s)
{
	while (s)
	{
		write(1, (char *) s, 1);
		s++;
	}
}

unsigned char	*ft_strjoin_free(unsigned char *str, unsigned char c)
{
	unsigned char	*new;
	size_t			size;

	if (!str)
		str = ft_calloc(1, sizeof(char));
	if (!str)
		return (NULL);
	size = 0;
	while (*str)
	{
		size++;
		str++;
	}
	str -= size;
	new = ft_calloc(1, size + 2);
	new[size] = c;
	while (size > 0)
	{
		new[size - 1] = str[size - 1];
		size--;
	}
	free(str);
	return (new);
}

void	handle_sig(int sig)
{
	static unsigned char	count;
	static unsigned char	c;
	static unsigned char	*str;
	pid_t					server_id;

	if (!c)
		c = 0;
	server_id = getpid();
	if (sig == SIGUSR1)
	{
		c ^= 1 << count;
		count++;
	}
	else if (sig == SIGUSR2)
		count++;
	if (count == 8)
		str = ft_strjoin_free(str, c);
	if (str && !*str)
		ft_putstr(str);
	if (sig == 2)
	{
		g_kill = 1;
		printf("\n[\033[0;31m%i\033[0;0m] Server Closed\n", server_id);
		return ;
	}
}

int	main(void)
{
	pid_t	server_id;

	if (!g_kill)
		g_kill = 0;
	signal(SIGINT, handle_sig);
	signal(SIGUSR1, handle_sig);
	signal(SIGUSR2, handle_sig);
	server_id = getpid();
	printf("[\033[0;32m%i\033[0;0m] Server Started\n", server_id);
	while (!g_kill)
		pause();
}
