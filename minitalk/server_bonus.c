/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaabi <akaabi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 15:26:24 by akaabi            #+#    #+#             */
/*   Updated: 2023/01/22 16:37:47 by akaabi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	cmp(int signal, int b)
{
	if (signal == SIGUSR1)
		b = 1;
	else
		b = 0;
	return (b);
}

void	handler(int signal, siginfo_t *info, void *p)
{
	static int	cip;
	static char	c;
	static int	a;
	int			b;

	(void)p;
	b = 0;
	if (cip != info->si_pid)
	{
		cip = info->si_pid;
		a = 0 ;
		c = 0 ;
	}
	b = cmp(signal, b);
	c += (b << a);
	a++;
	if (a == 8)
	{
		if (c == '\0')
			kill(cip, SIGUSR1);
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
	ft_putstr("Pid is : ");
	ft_putnbr(pid);
	ft_putchar('\n');
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
