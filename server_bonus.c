/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obraiki <obraiki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 09:39:52 by obraiki           #+#    #+#             */
/*   Updated: 2022/01/08 09:43:12 by obraiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	fmsg(int pid, int signum)
{
	if (kill(pid, signum) == -1)
		exit(EXIT_FAILURE);
}

void	bta(int signum, siginfo_t *inf, void *context)
{
	static char	c = 0xff;
	static int	bit = 0;
	static int	g_pid = 0;

	(void)context;
	if (g_pid != inf->si_pid)
	{
		c = 0xff;
		bit = 0;
		g_pid = inf->si_pid;
	}
	if (signum == SIGUSR1)
		c |= 0x80 >> bit;
	if (signum == SIGUSR2)
		c ^= 0x80 >> bit;
	if (bit++ == 8)
	{
		if (!c)
			fmsg(g_pid, SIGUSR1);
		ft_putchar(c);
				bit = 0;
				c = 0xff;
	}
}

int	main(int ac, char **av)
{
	struct sigaction	sa;
	int					pid;

	if (ac != 3 && av[1] != NULL)
	{
		ft_putstr("error\n");
		exit(1);
	}
	pid = getpid();
	sa.sa_sigaction = bta;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_putnbr(pid);
	ft_putchar('\n');
	while (1)
		pause();
	return (0);
}
