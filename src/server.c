/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 13:25:42 by arturhar          #+#    #+#             */
/*   Updated: 2024/05/04 13:29:05 by arturhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/minitalk.h"

void	receive_message(int signal)
{
	static int	bit;
	static int	i;

	if (signal == SIGUSR1)
		i |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		ft_printf("%c", i);
		bit = 0;
		i = 0;
	}
}

int	main(int argc, char **argv)
{
	pid_t	pid;

	pid = getpid();
	ft_printf("Server PID - %d\n", pid);
	(void)argv;
	while (argc == 1)
	{
		signal(SIGUSR1, receive_message);
		signal(SIGUSR2, receive_message);
		pause();
	}
	return (0);
}
