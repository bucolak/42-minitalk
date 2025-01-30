/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bucolak <bucolak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 14:33:46 by bucolak           #+#    #+#             */
/*   Updated: 2024/12/26 14:35:35 by bucolak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	wrs(int sig)
{
	static char	c = 0;
	static int	i = 0;

	if (sig == SIGUSR1)
	{
		c |= (1 << i);
	}
	else if (sig == SIGUSR2)
	{
		c |= (0 << i);
	}
	i++;
	if (i == 8)
	{
		ft_printf("%c", c);
		i = 0;
		c = 0;
	}
}

int	main(void)
{
	ft_printf("%d\n", getpid());
	while (42)
	{
		signal(SIGUSR1, wrs);
		signal(SIGUSR2, wrs);
		pause();
	}
	return (0);
}
