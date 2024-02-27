/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gachalif <gachalif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 14:51:59 by gachalif          #+#    #+#             */
/*   Updated: 2024/02/27 11:00:33 by gachalif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	g_kill;

unsigned char	*ft_putstr_free(unsigned char *s, siginfo_t *info)
{
	size_t	i;

	i = 0;
	ft_printf("[%s@%i%s] ", "\033[1;36m", info->si_pid, "\033[0;0m");
	while (s && s[i])
	{
		write(1, (char *) s + i, 1);
		s[i] = 0;
		i++;
	}
	write(1, "\n", 1);
	if (s)
		free(s);
	return (NULL);
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

void	handle_sig(int sig, siginfo_t *info, void *ucontext)
{
	static unsigned char	count;
	static unsigned char	c;
	static unsigned char	*str;
	pid_t					server_id;

	(void) ucontext;
	if (!c)
		c = 0;
	server_id = getpid();
	if (sig == SIGUSR1)
	{
		c ^= 1 << count;
		count++;
	}
	else if (sig == SIGUSR2)
	{
		c ^= 0 << count;
		count++;
	}
	if (count == 8)
	{
		str = ft_strjoin_free(str, c);
		count = 0;
		if (c == 0)
			str = ft_putstr_free(str, info);
		c = 0;
	}
	if (sig == 2)
	{
		g_kill = 1;
		printf("\n[\033[1;31m%i\033[0;0m] Server Closed\n", server_id);
		return ;
	}
}

int	main(void)
{
	pid_t				server_id;
	struct sigaction	sa;

	if (!g_kill)
		g_kill = 0;
	sa.sa_flags = SA_SIGINFO;
	sa.sa_mask = 0;
	sigaddset(&sa.sa_mask, SIGINT);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);
	sa.sa_sigaction = &handle_sig;
	if (sigaction(SIGUSR1, &sa, NULL) == -1 || \
	sigaction(SIGUSR2, &sa, NULL) == -1 || sigaction(SIGINT, &sa, NULL) == -1)
		return (1);
	server_id = getpid();
	printf("[\033[1;32m%i\033[0;0m] Server Started\n", server_id);
	while (!g_kill)
		pause();
}
//Utiliser sigaction pour log les PID des clients et leur renvoyer un ping.
