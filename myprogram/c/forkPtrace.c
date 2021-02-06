#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/ptrace.h>

int main()
{
	pid_t pid;
	int syscall_no;


	if((pid = fork()) == 0) {
		printf("Chuld proces \n");
		ptrace(PTRACE_TRACEME,0,NULL,NULL);
		execl("/bin/ls","ls",NULL);
		
	} else {
		sleep(1);
		waitpid(pid,NULL,0);
		puts(" this is parent call \n");
//		wait(NULL);
		syscall_no = ptrace(PTRACE_SYSCALL,pid,0,0);
		printf(" my syscall_no = %d \n",syscall_no);
		ptrace(PTRACE_CONT,pid,NULL,NULL);

	}
	return 0;
}
