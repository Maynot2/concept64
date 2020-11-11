#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// "hello brave new world"
// ["hello", "brave", "new", "world"]

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
		ary[i] = malloc(sizeof(char) * strlen(token));
		ary[i] = token;
		token = strtok(NULL, del);
		i++;
	}
	return ary;
}

int main(void)
{
	char sentence[] = "Hello brave new world!";
	char **ary;
	ary = splitstr(sentence);

	printf("ary: %s\n", ary[2]);

	return (0);
}
