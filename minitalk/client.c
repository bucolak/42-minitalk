/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buket <buket@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 22:33:21 by buket             #+#    #+#             */
/*   Updated: 2025/04/08 23:52:39 by buket            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	ft_atoi(char *str)
{
	int	i;
	int	s;
	int	r;

	i = 0;
	s = 1;
	r = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			s = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		r = r * 10 + str[i] - '0';
		i++;
	}
	return (s * r);
}

void send_signal(char s, int pid)
{
    int i = 0;
    while(i < 8)
    {
        if(((s>>i)&1)==1)
            kill(pid, SIGUSR1);
        else
            kill(pid, SIGUSR2);
        i++;
        usleep(100);
    }
}

int main(int argc, char *argv[])
{
    if(argc != 3)
    {
        ft_printf("Incorrect argument input\n");
        return 0;
    }
    int i = 0;
    while(argv[2][i])
    {
        send_signal(argv[2][i], ft_atoi(argv[1]));
        i++;
    }
    return 0;   
}

//header'ı değiştir