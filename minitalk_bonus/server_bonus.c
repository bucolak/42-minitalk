/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bucolak <bucolak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 15:10:02 by bucolak           #+#    #+#             */
/*   Updated: 2025/04/10 15:10:13 by bucolak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void handle_signal(int sig, siginfo_t *info, void *context)
{
    (void)context;
    static int c;
    static int i = 0;
    if(sig==SIGUSR1)
        c |= (1<<i);
    else if(sig == SIGUSR2)
        c |= 0;
    kill(info->si_pid, SIGUSR1);
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
    sa.sa_sigaction = handle_signal;
   
    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);
    while(42)
    {
        pause();
    }
    return 0;
}
