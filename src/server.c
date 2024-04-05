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

void	print_minitalk(void)
{
	ft_printf("\033[2J\033[1;1H");
	ft_printf("\n\n\n");
	ft_printf("                                                 ");
	ft_printf("\033[1;34m");
	ft_printf("███╗░░░███╗██╗███╗░░██╗██╗████████╗░█████╗░██╗░░░░░██╗░░██╗\n");
	ft_printf("                                                 ");
	ft_printf("████╗░████║██║████╗░██║██║╚══██╔══╝██╔══██╗██║░░░░░██║░██╔╝\n");
	ft_printf("                                                 ");
	ft_printf("██╔████╔██║██║██╔██╗██║██║░░░██║░░░███████║██║░░░░░█████═╝░\n");
	ft_printf("                                                 ");
	ft_printf("██║╚██╔╝██║██║██║╚████║██║░░░██║░░░██╔══██║██║░░░░░██╔═██╗░\n");
	ft_printf("                                                 ");
	ft_printf("██║░╚═╝░██║██║██║░╚███║██║░░░██║░░░██║░░██║███████╗██║░╚██\n");
	ft_printf("                                                 ");
	ft_printf("╚═╝░░░░░╚═╝╚═╝╚═╝░░╚══╝╚═╝░░░╚═╝░░░╚═╝░░╚═╝╚══════╝╚═╝░░╚═╝\n");
	ft_printf("                                                 ");
	ft_printf("\033[0;36m");
}

void	print_details(pid_t pid)
{
	ft_printf("         ");
	ft_printf("Welcome to arturhar's Minitalk server!\n");
	ft_printf("                                                 ");
	ft_printf("                  ");
	ft_printf("Server PID - %d", pid);
	ft_printf("\n\n");
}

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

	(void)argv;
	if (argc != 1)
	{
		return (1);
	}
	pid = getpid();
	print_minitalk();
	print_details(pid);
	while (1)
	{
		signal(SIGUSR1, receive_message);
		signal(SIGUSR2, receive_message);
		pause();
	}
	return (0);
}
