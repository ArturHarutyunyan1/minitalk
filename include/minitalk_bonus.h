/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arturhar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 13:25:42 by arturhar          #+#    #+#             */
/*   Updated: 2024/05/04 13:29:05 by arturhar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include "../ft_printf/include/ft_printf.h"
# include "../libft/libft.h"
# include <unistd.h>
# include <signal.h>
# include <unistd.h>

void	receive_message(int signal, siginfo_t *info, void *s);
void	send_message(pid_t pid, int i);

#endif
