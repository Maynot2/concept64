#include <stdio.h>
#include <unistd.h>

/**
 * main - fork example
 *
 * Return: Always 0.
 */
int main(void)
{
	pid_t my_pid;
	pid_t id;

	printf("Before fork\n");
	id = fork();
	if (id == -1)
	{
		perror("Error:");
		return (1);
	}
	printf("Middle fork\n");
	if ( id != 0)
		fork();
	printf("After fork\n");
	my_pid = getpid();
	printf("My pid is %u\n", my_pid);
	return (0);
}
