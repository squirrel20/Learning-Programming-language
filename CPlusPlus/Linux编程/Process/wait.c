#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void err_sys(char *);
void pr_exit(int);

int
main(void)
{
    pid_t   pid;
    int     status;

    if((pid = fork()) < 0)
        err_sys("fork error");
    else if(pid == 0)
		exit(7);

	if(wait(&status) != pid)
		err_sys("wait error");
	pr_exit(status);


    return 0;
}

void
err_sys(char *arr)
{
	puts(arr);
	exit(7);
}

void
pr_exit(int status)
{
	if(WIFEXITED(status))
		printf("normal termination, exit status = %d\n", WEXITSTATUS(status));
	else if (WIFSIGNALED(status))
		printf("abnormal termination, signal number = %d%s\n", WTERMSIG(status),
#ifdef WCOREDUMP
				WCOREDUMP(status) ? " (core file generated)" : "");
#else
				"");
#endif
	else if(WIFSTOPPED(status))
		printf("child stopped, signal number = %d\n", WSTOPSIG(status));
}
