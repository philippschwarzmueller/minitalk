/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pschwarz <pschwarz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 10:15:53 by pschwarz          #+#    #+#             */
/*   Updated: 2022/12/12 14:37:38 by pschwarz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <fcntl.h>
#include "minitalk.h"

int	main(int argc, char **argv)
{
	kill(atoi(argv[argc - 1]), 9);
	return (0);
}
