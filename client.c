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

int	main(int argc, char **argv)
{
	char	*binarystr;
	int		i;

	if (argc != 3)
		return (ft_printf("Error: Args should be PID and string\n"), 0);
	if (!ft_atoi(argv[argc - 2]))
		return (ft_printf("Error: PID needs to be a number\n"), 0);
	binarystr = ft_strtorevb(argv[argc - 1]);
	i = 0;
	ft_printf("%s EOL\n", binarystr);
	while (binarystr[i] != '\0')
	{
		if (binarystr[i] == '1')
			kill(ft_atoi(argv[argc - 2]), SIGUSR1);
		else if (binarystr[i] == '0')
			kill(ft_atoi(argv[argc - 2]), SIGUSR2);
		else
			ft_printf("error sending signal");
		i++;
		usleep(100);
	}
	free(binarystr);
	return (0);
}

static char	*ft_strtorevb(char *s)
{
	char	*res;
	int		len;
	int		i;
	int		k;

	len = ft_strlen(s);
	res = ft_calloc(len * 8 + 1, sizeof(char));
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
