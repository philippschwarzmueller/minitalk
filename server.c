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

void	signal_handler(int sig);
char	ft_bintoc(char *b);

int	main(void)
{
	ft_printf("%d\n", getpid());
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	while (1)
		pause();
	return (0);
}

void	signal_handler(int sig)
{
	static char	*received_char;
	static int	bit_count;

	bit_count++;
	if (!received_char)
		received_char = "";
	if (sig == 30)
		received_char = ft_strjoin(received_char, "1");
	else if (sig == 31)
		received_char = ft_strjoin(received_char, "0");
	if (bit_count == 8)
	{
		ft_printf("%c", ft_bintoc(received_char));
		received_char = "";
		bit_count = 0;
	}
}

char	ft_bintoc(char *b)
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
