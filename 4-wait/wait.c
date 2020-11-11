#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


/**
 * main - fork example
 *
 * Return: Always 0.
 */
int main(void)
{
	char *argv[] = {"/bin/ls", "/tmp", NULL};
	pid_t my_pid;
	int id;
	int i, j= 0, k;
	int n;

	id = fork();
	for (i = 0; i <= 4; i++)
	{
		if(id == 0)
		{
			execve(argv[0], argv, NULL);
		}

		if (id != 0)
		{
			wait(&n);
			if (i != 4)
				id = fork();
		}
	}

	my_pid = getpid();
	printf("My pid is %u\n", my_pid);
	return (0);
}
