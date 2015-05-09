#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

char	*env_init[] = {"USER", NULL};

int
main(void)
{
	pid_t	pid;

	if ((pid = fork()) < 0){
		puts("fork error");
		return 0;
	}else if(pid == 0){
		if(execvp("echo", env_init) < 0){
			puts("execle error");
			return 0;
		}
	}

	return 0;
}
