/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus_utils.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obraiki <obraiki@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 09:40:56 by obraiki           #+#    #+#             */
/*   Updated: 2022/01/08 09:48:14 by obraiki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include<unistd.h>
# include<signal.h>
# include<stdlib.h>

void	ft_putchar(char c);
void	ft_putstr(char *s);
void	ft_putnbr(long n);
void	binary(int pid, char *s);
int		ft_atoi(const char *s);

#endif
