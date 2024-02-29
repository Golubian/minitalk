/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gachalif <gachalif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 15:01:34 by gachalif          #+#    #+#             */
/*   Updated: 2024/02/29 13:29:08 by gachalif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int		ft_atoi(char *s);
char	*ft_strdup(char *s);

static char	g_received;

static void	await_response(int sig)
{
	int	i;

	if (sig == SIGUSR1)
	{
		g_received = 1;
		return ;
	}
	i = 0;
	while (i++ < 1000)
		if (!usleep(500) && g_received == 1)
			return ;
	return ;
}

static int	send_char(int pid, char c)
{
	char	iter;

	iter = 0;
	while (iter < 8)
	{
		if ((c & 0x01) == 0)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		c = c >> 1;
		usleep(50);
		iter++;
	}
	return (1);
}

static int	send_string(int pid, char *s)
{
	while (s && *s)
	{
		send_char(pid, *s);
		s++;
	}
	send_char(pid, 0);
	return (1);
}

static int	validate_pid(char *pid)
{
	if (!pid || !*pid)
		return (printf("%s", "\033[1;31mEmpty pid is invalid\
		\n\nUsage: ./client <pid> <message>\n"), 0);
	if (*pid == '0')
		return (printf("%s", "\033[1;31mPid of 0 is dangerous!\
			\n\nUsage: ./client <pid> <message>\n"), 0);
	if (*pid == '-')
	{
		pid++;
		if (pid[0] == '1' && pid[1] == 0)
		{
			return (printf("\033[1;31mPid of -1 is dangerous!\
			\n\nUsage: ./client <pid> <message>\n"), 0);
		}
	}
	while (pid && *pid)
	{
		if (*pid >= '0' && *pid <= '9')
			pid++;
		else
			return (printf("\033[1;31mPid should be numerical only\
		\n\nUsage: ./client <pid> <message>\n"), 0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	pid_t	pid;

	g_received = 0;
	signal(SIGUSR1, await_response);
	if (argc < 3)
		return (printf("%s", "\033[1;31mArgument count invalid\
		\n\nUsage: ./client <pid> <message>\n"), 1);
	if (!validate_pid(argv[1]))
		return (1);
	pid = ft_atoi(argv[1]);
	if (pid < 0)
		printf("%s", "\033[1;33mWARNING: You sent a negative pid\033[0m\n");
	if (!send_string(pid, argv[2]))
		printf("\033[1;31m\"%s\" - / SIGNAL FAILED TO SEND \
/ - [%i]\n", argv[2], pid);
	else
	{
		printf("\"%s\" -?> [\033[1;33m@%i\033[0;0m] \033[1;32mSENT\033[0;0m\n", \
		argv[2], pid);
		await_response(0);
		if (g_received == 1)
			printf("[\033[1;33m@%i\033[0;0m] -> \
\033[1;32mRESPONSE RECEIVED OK\033[0;0m\n", pid);
		else
			printf("[\033[1;33m@%i\033[0;0m] -\\> \033[1;31mNO RESPONSE \
TIMED OUT\033[0;0m\n", pid);
	}
}
