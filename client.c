/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pschwarz <pschwarz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 10:15:53 by pschwarz          #+#    #+#             */
/*   Updated: 2023/01/08 15:37:53 by pschwarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static char	*ft_strtorevb(char *s);

int	main(int argc, char **argv)
{
	char	*binarystr;
	int		i;

	binarystr = ft_strtorevb(argv[argc - 1]);
	i = 0;
	ft_printf("%s EOL\n", binarystr);
	while (binarystr[i] != '\0')
	{
		if (binarystr[i] == '1')
			kill(atoi(argv[argc - 2]), SIGUSR1);
		else if (binarystr[i] == '0')
			kill(atoi(argv[argc - 2]), SIGUSR2);
		else
			ft_printf("error sending signal");
		i++;
		sleep(1);
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

/* static char	*ft_stob(char *s)
{
	int		len;
	int		i;
	int		j;
	char	ch;
	char	*res;

	if (s == NULL)
		return (NULL);
	i = 0;
	j = 0;
	len = ft_strlen(s);
	res = malloc(len * 8 + 1);
	if (!res)
		return (NULL);
	res[0] = '\0';
	while (s[i] != '\0')
	{
		ch = s[i];
		while (j < 8)
		{
			if (!(ch & 1))
				ft_strlcat(res, "0", 1);
			else
				ft_strlcat(res, "1", 1);
			j++;
		}
		j = 0;
		i++;
	}
	return (res);
}
 */
