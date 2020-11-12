#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>


int _strlen(char *s)
{
	int i;

	if (!s)
		return (0);

	i = 0;
	while(s[i])
		i++;

	return(i);
}

/**
 * _strstr - Finds the first occurrence of the substring needle in string
 * haystack
 * @haystack: A pointer to a string.
 * @needle: A pointer to a string.
 *
 * Return: A pointer to a string on success.
 *         NULL on error
 *
 */

char *_strstr(char *haystack, char *needle)
{
	int i = 0, j;
	int nd_len = _strlen(needle);

	if (!*needle)
		return (haystack);

	while (*(haystack + i))
	{
		j = 0;
		while (*(haystack + i + j) == *(needle + j))
		{
			if (nd_len - 1 == j)
			{
				return (haystack + i);
			}
			j++;
		}
		i++;
	}
	return (NULL);
}

char *findPATH(char **env)
{
	int i, j;
	char *path;

	i = 0;
	while (env[i])
	{
		if (_strstr(env[i], "PATH="))
		{
			path = malloc(sizeof(char) * (_strlen(env[i] + 1)));
			if (path == NULL)
				exit(1);

			j = 0;
			while(env[i][j])
			{
				path[j] = env[i][j];
				j++;
			}
			path[j] = '\0';
		}
		i++;
	}
	return (path);
}

char **splitstr(char *str, char *del)
{
	char **ary;
	char *token;
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

/**
 * _strcat - Concatenates two strings dest and source.
 * @dest: A pointer to the destination string.
 * @src: A pointer to the source string.
 *
 * Return: The pointer to the destination string.
 *
 */


char *_strcat(char *dest, char *src)
{
	int i = 0, j;

	while (dest[i])
		i++;

	for (j = 0; j < _strlen(src); j++)
	{
		dest[i] = src[j];
		i++;
	}

	return (dest);
}

int main(int argc, char **argv, char **envp)
{
	char **paths;
	char *usage_msg = "Usage _which filename ...\n";
	char *cmd;
	struct stat st;
	int i, j;

	if (argc < 2)
	{
		write(STDERR_FILENO, usage_msg, _strlen(usage_msg));
		exit(1);
	}

	paths = splitstr(findPATH(envp), "=:");

	// add command at end of path to test if command is present in dir.
	// /bin + /ls ----> stst("/bin/ls", &st) == 0

	// loop over argv using counter i

	j = 0;
	while(paths[j])
	{
		if (stat(paths[j], &st) == 0)
		{
			write(STDOUT_FILENO, paths[j], _strlen(paths[j]));
			write(STDOUT_FILENO, "\n", 1);
		}
		j++;
	}
	return (0);
}
