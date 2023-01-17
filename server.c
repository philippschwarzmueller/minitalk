/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pschwarz <pschwarz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 10:16:03 by pschwarz          #+#    #+#             */
/*   Updated: 2023/01/09 09:03:22 by pschwarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	signal_handler(int sig, siginfo_t *siginfo, void *ctx);
static char	ft_bintoc(char *b);

int	main(void)
{
	struct sigaction	sigact;

	sigact.sa_sigaction = &signal_handler;
	sigact.sa_flags = SA_SIGINFO;
	ft_printf("PID: %d\n", getpid());
	sigaction(SIGUSR1, &sigact, NULL);
	sigaction(SIGUSR2, &sigact, NULL);
	while (1)
		pause();
	return (0);
}

static void	signal_handler(int sig, siginfo_t *siginfo, void *ctx)
{
	static char	*received_char;
	static int	bit_count;
	char		c;

	(void) ctx;
	bit_count++;
	if (!received_char)
		received_char = "";
	if (sig == 30)
		received_char = ft_strjoin(received_char, "1");
	else if (sig == 31)
		received_char = ft_strjoin(received_char, "0");
	if (bit_count == 8)
	{
		c = ft_bintoc(received_char);
		if (c == '\0')
		{
			write(1, "\n", 1);
			kill(siginfo->si_pid, SIGUSR1);
		}
		else
			write(1, &c, 1);
		received_char = "";
		bit_count = 0;
	}
}

static char	ft_bintoc(char *b)
{
	char	res;
	int		i;

	res = 0;
	i = 0;
	while (b[i] != '\0')
	{
		if (b[i] == '1')
			res = res ^ (1 << (7 - i));
		i++;
	}
	return (res);
}
