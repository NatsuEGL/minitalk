/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaabi <akaabi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 18:08:31 by akaabi            #+#    #+#             */
/*   Updated: 2023/01/23 23:36:54 by akaabi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <stdio.h>
# include <unistd.h>

void	ft_putchar(char c);
void	ft_putnbr(int nbr);
void	ft_putstr(char *s);
int		ft_atoi(const char *str);

#endif