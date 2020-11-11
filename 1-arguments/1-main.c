#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
	char buff[100];
	char *buffer = buff;
	size_t size = 100;
	ssize_t c_count;

	write(STDOUT_FILENO, "$ ", 2);
	c_count = getline(&buffer, &size, stdin);
	if (c_count == -1)
		exit(92);
	printf("Char count: %zd\n", c_count);
	write(STDOUT_FILENO, buffer, c_count);

	return(0);
}
