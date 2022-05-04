/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkhatib <bkhatib@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 18:12:35 by bkhatib           #+#    #+#             */
/*   Updated: 2022/05/04 15:05:06 by bkhatib          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	main(int argc, char **argv)
{
	pid_t	serverpid;
	
	signal(SIGUSR1, handler);
	if (argc == 3)
	{
		serverpid = ft_atoi(argc[1]);
		ft_stream_str(argv[2], serverpid);
	}
	else
		write(1, "Usage: ./client [server PID] [message]\n", 39);
}