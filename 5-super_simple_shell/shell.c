#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/**
 * _strlen - Computes the size of a string s.
 * @s: A pointer to a string.
 *
 * Return: A integer.
 *
 */

int _strlen(char *s)
{
	int c = 0;

	if (s == NULL)
		return (c);

	while (*(s + c))
		c++;
	return (c);
}

char **splitstr(char *str)
{
	char **ary;
	char *token;
	char *del = " ";
	int i;

	ary = malloc(sizeof(char *));
	if (!ary)
		return (NULL);
	token = strtok(str, " ");

	i = 0;
	while (token)
	{
		ary[i] = malloc(sizeof(char) * _strlen(token));
		ary[i] = token;
		token = strtok(NULL, del);
		i++;
	}
	ary[i] = malloc(100);
	ary[i] = NULL;

	return ary;
}

void remove_new_line(char **buff, size_t c)
{
	size_t i;
	char *cpbuff = strdup(buff[i]);
	printf("cpbuff: %s\n", cpbuff);
	printf("count: %zu\n", c);
	for (i = 0; i < c; i++)
	{
		if (i > c - 1)
			*buff[i] = '\0';
		printf("%zu\n", i);
		*buff[i] = cpbuff[i];
	}
	printf("i after: %zu", i);
	//*buff[i] = '\0';
}

int main(void)
{
	char *buffer[1024];
	ssize_t size = 1024;
	size_t count;
	char **args;
	char *args2[] = {"/bin/ls", NULL};

	// Come back here

	write(STDOUT_FILENO, "$ ", 3);
	count = getline(buffer, &size, stdin);
	puts("here");
	remove_new_line(buffer, count);
	printf("buffer[0]: %s", buffer[0]);
	args = splitstr(buffer[0]);

	printf("arg1: %s", args[0]);
	printf("arg2: %s", args[1]);
	if (execve(args2[0], args2, NULL) == -1)
	{
		perror("Error\n");
	}

	return (0);
}
