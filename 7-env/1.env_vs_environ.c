#include <unistd.h>
#include <stdio.h>

int main(int argc, char **argv, char **envp)
{
	extern char **environ;

	printf("envp address = %p\n", envp);
	printf("environ address = %p\n", environ);
}
