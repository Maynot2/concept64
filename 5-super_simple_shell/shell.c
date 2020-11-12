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

char *hsh_readline(void)
{
	char *buffer[1] = {NULL};
	ssize_t size = 1;

	if (getline(buffer, &size, stdin) == -1) // read line
		perror("Read Error\n");
	return (buffer[0]);
}

void display_prompt(void)
{
	if (write(STDOUT_FILENO, "$ ", 3) == -1) // display prompt
		perror("Write Error\n");

}
char **splitstr(char *str)
{
	char **ary;
	char *token;
	char *del = " \t\r\n\v\f";
	int i, j;
	int size = 8;

	ary = malloc(sizeof(char *) * size);
	if (!ary)
		exit(1);

	token = strtok(str, del);

	i = 0;
	while (token)
	{
		if (i >= size - 1)
		{
			size += size;
			ary = realloc(ary, sizeof(char *) * size);
		}
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
	ary[i] = NULL;
	return ary;
}

void hsh_exec_cmd(char **arguments)
{
	if (execve(arguments[0], arguments, NULL) == -1)
		perror("Execution Error\n");
}

int main(void)
{
	int status = 1;
	char **args;
	char *line;
	pid_t id;

	while (status)
	{
		id = fork();
		if (id == 0)
		{
			display_prompt();
			line = hsh_readline();
			args = splitstr(line);
			hsh_exec_cmd(args);
			free(line);
			free(args);
		}
		else
		{
			wait(NULL);
		}
	}

	return (0);
}
