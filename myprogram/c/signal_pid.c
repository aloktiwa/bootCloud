#include <stdio.h>
#include <signal.h>

void get_pid(int sig, siginfo_t *info, void *context)
{
        printf("PID of signal sender = %d\n", info->si_pid);
}

int main(int argc, char **argv)
{
        struct sigaction        sa;

        printf("PID: %d\n", getpid());       //display PID for kill()
        sa.sa_flags = SA_SIGINFO;
        sa.sa_sigaction = get_pid;
        sigaction(SIGUSR1, &sa, NULL);
        pause();                            //wait for a signal
}
