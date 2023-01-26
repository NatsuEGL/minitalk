/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaabi <akaabi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 15:33:59 by akaabi            #+#    #+#             */
/*   Updated: 2023/01/24 13:51:38 by akaabi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_sendm(int pid, char c)
{
	int	a;
	int	b;

	a = 1;
	b = 7;
	while (b > 0)
	{
		if (c & a)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(800);
		a = a << 1;
		b--;
	}
}

int	main(int argc, char **argv)
{
	int	i;
	int	pid;

	if (argc != 3)
		return (1);
	pid = ft_atoi(argv[1]);
	if (pid <= 0)
		return (1);
	i = 0;
	while (argv[2][i])
	{
		ft_sendm(pid, argv[2][i]);
		i++;
	}
	ft_sendm(pid, 0);
	return (0);
}
