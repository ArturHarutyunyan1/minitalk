/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 13:25:42 by arturhar          #+#    #+#             */
/*   Updated: 2024/05/04 13:29:05 by arturhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../include/minitalk_bonus.h"

void	receive_message(int signal, siginfo_t *info, void *s)
{
    static int	bit;
    static int	i;

    (void)info;
    (void)s;
    if (signal == SIGUSR1)
        i |= (0x01 << bit);
    bit++;
    if (bit == 8)
    {
        ft_printf("%c", i);
        bit = 0;
        i = 0;
        kill(info->si_pid, SIGUSR2);
    }
}

int	main(int argc, char **argv)
{
    pid_t	pid;
    struct sigaction sig;
    if (argc != 1)
    {
        ft_printf("WRONG FORMAT!!!\n");
        ft_printf("USAGE: ./server\n");
        return (1);
    }
    pid = getpid();
    ft_printf("Server PID - %d\n", pid);
    (void)argv;
    sig.sa_sigaction = receive_message;
    sigemptyset(&sig.sa_mask);
    sig.sa_flags = 0;
    while (argc == 1)
    {
        sigaction(SIGUSR1, &sig, NULL);
        sigaction(SIGUSR2, &sig, NULL);
        pause();
    }
}
