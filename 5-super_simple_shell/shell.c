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
	char *del = " \t\r\n\v\f";
	int i, j;

	ary = malloc(sizeof(char *));
	if (!ary)
		return (NULL);
	token = strtok(str, del);

	i = 0;
	while (token)
	{
		ary[i] = malloc(sizeof(char) * _strlen(token));
		if (ary[i] == NULL)
		{
			for(j = 0; j < i; j++)
				free(ary[j]);
			free(ary);
		}
		ary[i] = token;
		token = strtok(NULL, del);
		i++;
	}
	ary[i] = malloc(8);
	ary[i] = NULL;
	return ary;
}

int main(void)
{
	char *buffer[1024];
	ssize_t size = 1024;
	int const TRUE = 1;
	char **args;
	pid_t id;

	while (TRUE)
	{
		id = fork();
		if (id == 0)
		{
			if (write(STDOUT_FILENO, "$ ", 3) == -1)
				perror("Write Error\n");
			if (getline(buffer, &size, stdin) == -1)
				perror("Read Error\n");

			args = splitstr(buffer[0]);
			
			if (execve(args[0], args, NULL) == -1)
				perror("Execution Error\n");
		}
		else
		{
			wait(NULL);
		}
	}

	return (0);
}
