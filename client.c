/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkhatib <bkhatib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 18:12:35 by bkhatib           #+#    #+#             */
/*   Updated: 2022/05/30 15:33:43 by bkhatib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_cond;

void	stream_char(pid_t pid, char c)
{
	int	bit;
	int	r;

	bit = 0;
	r = 0;
	g_cond = 1;
	while (bit < CHAR_BIT && g_cond)
	{
		g_cond = 0;
		if (c & 1)
			r = kill(pid, SIGUSR1);
		else
			r = kill(pid, SIGUSR2);
		if (r == -1)
			ft_error("Invalid PID.\n");
		if (!g_cond)
			usleep(200);
		c >>= 1;
		usleep(200);
		if (!g_cond)
			ft_error("Signal failed to send.\n");
		bit++;
	}
}

void	stream_msg(pid_t pid, char *msg)
{
	while (*msg != '\0')
	{
		stream_char(pid, *msg);
		msg++;
	}
	write(1, "String sent successfully.\n", 26);
}

void	handler(int sig)
{
	(void)sig;
	g_cond = 1;
}

int	main(int argc, char **argv)
{
	pid_t	serverpid;

	signal(SIGUSR1, handler);
	if (argc == 3)
	{
		serverpid = ft_atoi(argv[1]);
		stream_msg(serverpid, argv[2]);
	}
	else
		write(1, "Usage: ./client [server PID] [message]\n", 39);
	return (0);
}
