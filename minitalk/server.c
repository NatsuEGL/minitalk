/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaabi <akaabi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 15:33:55 by akaabi            #+#    #+#             */
/*   Updated: 2023/01/23 20:04:31 by akaabi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler(int signal, siginfo_t *info, void *p)
{
	static int	cip;
	static char	c;
	static int	a;
	int			b;

	b = 0;
	(void)p;
	if (cip != info->si_pid)
	{
		cip = info->si_pid;
		a = 0;
		c = 0;
	}
	if (signal == SIGUSR1)
		b = 1;
	else
		b = 0;
	c += (b << a);
	a++;
	if (a == 7)
	{
		write(1, &c, 1);
		a = 0;
		c = 0;
	}
}

int	main(void)
{
	int					pid;
	struct sigaction	sa;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = handler;
	pid = getpid();
	ft_putstr("Pid : ");
	ft_putnbr(pid);
	ft_putchar('\n');
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
