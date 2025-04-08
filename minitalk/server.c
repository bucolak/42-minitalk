/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buket <buket@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 22:52:42 by buket             #+#    #+#             */
/*   Updated: 2025/04/08 23:58:43 by buket            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void handle_signal(int sig, siginfo_t *info, void *context)
{
    (void)info;
    (void)context;
    static int c;
    static int i = 0;
    if(sig==SIGUSR1)
        c |= (1<<i);
    else if(sig == SIGUSR2)
        c |= 0;
    i++;
    if(i==8)
    {
        ft_printf("%c",c);
        i = 0;
        c = 0;
    }
}

int main()
{
    int pid;
    struct sigaction sa;
    pid = getpid();
    ft_printf("PID : %d\n",pid);
    sa.sa_flags = SA_SIGINFO;
    sa.__sigaction_u.__sa_sigaction=handle_signal;
    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);
    while(42)
    {
        pause();
    }
    return 0;
}

//header'ı değiştir