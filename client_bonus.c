/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 10:32:17 by arturhar          #+#    #+#             */
/*   Updated: 2024/04/17 10:56:57 by arturhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

int	ft_atoi(const char *str)
{
	int	neg;
	int	num;
	int	i;

	i = 0;
	neg = 1;
	num = 0;
	while ((str[i] == ' ' || (str[i] == '\n') || (str[i] == '\t')
			|| (str[i] == '\v') || (str[i] == '\f') || str[i] == '\r'))
		i++;
	if ((str[i] == '-') || (str[i] == '+'))
	{
		if (str[i] == '-')
			neg *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - 48);
		i++;
	}
	return (num * neg);
}

static void	confirm(int signal)
{
	if (signal == SIGUSR1)
		write(1, " ", 1);
	else
		write (1, " ", 1);
}

void	send_message(pid_t pid, char c)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if ((c & (0x01 << i)) != 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
		i++;
	}
}

int	main(int argc, char **argv)
{
	pid_t	pid;
	int		i;

	if (argc != 3)
	{
		write (2, "Wrong Usage!\n", 13);
		exit (write (2, "./client_bonus <PID> <MESSAGE>\n", 30));
	}
	i = 0;
	pid = ft_atoi(argv[1]);
	while (argv[2][i])
	{
		signal(SIGUSR1, confirm);
		signal(SIGUSR2, confirm);
		send_message(pid, argv[2][i]);
		i++;
	}
	send_message(pid, '\n');
	return (0);
}
