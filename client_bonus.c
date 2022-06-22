/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obraiki <obraiki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 09:38:32 by obraiki           #+#    #+#             */
/*   Updated: 2022/01/08 11:12:56 by obraiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	msg(int signum)
{
	if (signum == SIGUSR1)
		ft_putstr("\nwell done\n");
}

void	binary(int pid, char *s)
{
	int	i;
	int	bit;	

	i = 0;
	if (!s)
		exit(1);
	while (1)
	{
		bit = -1;
		while (++bit < 9)
		{
			if (s[i] & (128 >> bit))
			{
				if (kill(pid, SIGUSR1) == -1)
					exit(1);
			}
			else
				if (kill(pid, SIGUSR2) == -1)
					exit(1);
			usleep(300);
		}
		if (!s[i])
			break ;
		i++;
	}
}

int	main(int ac, char **av)
{
	int	pd;

	if (ac != 3 || av[2][0] == '\0')
	{
		ft_putstr("error\n");
		exit(1);
	}
	signal(SIGUSR1, msg);
	pd = ft_atoi(av[1]);
	if (pd == -1)
	{
		ft_putstr("error\n");
		exit(1);
	}
	binary(pd, av[2]);
}
