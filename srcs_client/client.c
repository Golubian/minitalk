/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gachalif <gachalif@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 15:01:34 by gachalif          #+#    #+#             */
/*   Updated: 2024/02/27 08:52:10 by gachalif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int		ft_atoi(char *s);
char	*ft_strdup(char *s);

int	send_char(int pid, char c)
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

int	send_string(int pid, char *s)
{
	while (s && *s)
	{
		send_char(pid, *s);
		s++;
	}
	send_char(pid, 0);
	return (1);
}

int	validate_pid(char *pid)
{
	if (!pid || !*pid)
		return (printf("\033[0;31mEmpty pid is invalid\
		\n\nUsage: ./client <pid> <message>\n"), 0);
	if (*pid == '-')
		pid++;
	while (pid && *pid)
	{
		if (*pid >= '0' && *pid <= '9')
			pid++;
		else
			return (printf("\033[0;31mPid should be numerical only\
		\n\nUsage: ./client <pid> <message>\n"), 0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	pid_t	pid;

	if (argc < 3)
		return (printf("\033[0;31mArgument count invalid\
		\n\nUsage: ./client <pid> <message>\n"), 1);
	if (!validate_pid(argv[1]))
		return (1);
	pid = ft_atoi(argv[1]);
	if (pid < 0)
		printf("\033[0;33mWARNING: You sent a negative pid\033[0m\n");
	if (!send_string(pid, argv[2]))
		printf("\033[0;31m\"%s\" - / SIGNAL FAILED TO SEND \
/ - [%i]\n", argv[2], pid);
	else
		printf("\"%s\" - > [%i]\n", argv[2], pid);
}
