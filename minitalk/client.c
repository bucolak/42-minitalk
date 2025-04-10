/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bucolak <bucolak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 22:33:21 by buket             #+#    #+#             */
/*   Updated: 2025/04/10 16:05:02 by bucolak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

volatile sig_atomic_t cont;

size_t	ft_strlen(const char *x)
{
	size_t	i;

	i = 0;
	while (x[i] != '\0')
	{
		i++;
	}
	return (i);
}

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

void send_cont(int sig)
{
    if(sig == SIGUSR1)
        cont = 1;
}

void send_signal(char s, int pid)
{
    int i = 0;
    while(i < 8)
    {
        cont = 0;
        if(((s>>i)&1)==1)
            kill(pid, SIGUSR1);
        else
            kill(pid, SIGUSR2);
        while (cont==0)
            ;
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
    if(ft_atoi(argv[1]) < 0 || ft_atoi(argv[1]) > 4194304 || ft_strlen(argv[1]) > 7)
    {
        ft_printf("WRONG PID!\n");
    }
    int i = 0;
    signal(SIGUSR1, send_cont);
    while(argv[2][i])
    {
        if((unsigned char)argv[2][i]>127)
        {
            ft_printf("bonusa geçin\n");
            return 0;
        }
        send_signal(argv[2][i], ft_atoi(argv[1]));
        i++;
    }
    return 0;   
}
