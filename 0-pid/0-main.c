#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main(void)
{
	pid_t curr_pid;
	pid_t parent_pid;

	curr_pid = getpid();
	parent_pid = getppid();
	printf("pid: %u\n", curr_pid);
	printf("ppid: %u\n", parent_pid);
	return (0);
}
