/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pschwarz <pschwarz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 10:15:53 by pschwarz          #+#    #+#             */
/*   Updated: 2023/01/09 10:54:18 by pschwarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static char	*ft_strtorevb(char *s);
static void	send_binary_str(char *str, int pid);
static void	signal_handler(int sig);

int	main(int argc, char **argv)
{
	char	*binarystr;

	if (argc != 3)
		return (ft_printf("Error: Args should be PID and string\n"), 0);
	if (!ft_atoi(argv[argc - 2]))
		return (ft_printf("Error: PID needs to be a number\n"), 0);
	signal(SIGUSR1, signal_handler);
	binarystr = ft_strtorevb(argv[argc - 1]);
	send_binary_str(binarystr, ft_atoi(argv[argc - 2]));
	free(binarystr);
	while (1)
		pause();
	return (0);
}

static void	send_binary_str(char *str, int pid)
{
	int	i;
	int	j;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '1')
			kill(pid, SIGUSR1);
		else if (str[i] == '0')
			kill(pid, SIGUSR2);
		else
			ft_printf("error: failed to send string\n");
		i++;
		usleep(100);
	}
	j = 8;
	while (j > 0)
	{
		kill(pid, SIGUSR2);
		j--;
		usleep(100);
	}
}

static char	*ft_strtorevb(char *s)
{
	char	*res;
	int		len;
	int		i;
	int		k;

	len = ft_strlen(s);
	res = ft_calloc((len * 8) + 1, sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	k = 0;
	while (s[i] != '\0')
	{
		while (k < 8)
		{
			if (s[i] & (1 << k))
				res[(i * 8) + 7 - k] = '1';
			else
				res[(i * 8) + 7 - k] = '0';
			k++;
		}
		k = 0;
		i++;
	}
	return (res);
}

static void	signal_handler(int sig)
{
	if (sig == SIGUSR1)
	{
		write(1, "Server received the string\n", 27);
		exit(EXIT_SUCCESS);
	}
	else
		exit(EXIT_FAILURE);
}
