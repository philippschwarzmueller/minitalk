/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pschwarz <pschwarz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 10:16:03 by pschwarz          #+#    #+#             */
/*   Updated: 2022/12/12 14:37:11 by pschwarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include "minitalk.h"

int	main(void)
{
	ft_printf("%d\n", getpid());
	while (1)
		sleep(20);
	return (1);
}
