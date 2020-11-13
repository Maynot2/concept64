#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int _strlen(char *s)
{
	int c = 0;

	if (s == NULL)
		return (c);

	while (*(s + c))
		c++;
	return (c);
}

typedef struct dir 
{
	char *str;
	struct dir *next;

} dir_t;

/**
 * add_node_end - Adds a node at the end of a linked list.
 * @head: A pointer to a pointer to the first element of the list.
 * @str: A string.
 *
 * Return: The address of the new element on success.
 *         NULL on failure.
 *
 */

dir_t *add_node_end(dir_t **head, const char *str)
{
	dir_t *new_tail;
	dir_t *curr_node;
	char *str_cp;

	puts("ok2");
	new_tail = malloc(sizeof(dir_t));
	if (!new_tail)
		return (NULL);

	str_cp = strdup(str);
	new_tail->str = str_cp;
	new_tail->next = NULL;
	puts("ok3");

	if (*head == NULL)
	{
		puts("ok6");
		*head = new_tail;
		return (*head);
	}
	puts("ok4");
	curr_node = *head;
	while (curr_node->next)
		curr_node = curr_node->next;
	curr_node->next = new_tail;
	puts("ok5");

	return (new_tail);
}

dir_t *splitdir(char *dirs)
{
	dir_t **head;
	char *token;
	char *delim = ":";

	*head = NULL;

	token = strtok(dirs, delim);

	while(token)
	{
		add_node_end(head, token);
		token = strtok(NULL, delim);
	}
	puts("OK");
	return (*head);
}

char *_getenv(const char *name)
{
	extern char **environ;
	char *result;
	int i, j,k, namelen;
	

	for (i = 0; environ[i] != strstr(environ[i],name); i++)
	{}
	for(j = 0; environ[i][j] != '\0'; j++)
	{}

	result = malloc(sizeof(char) * 100000);

	namelen = strlen(name);
	k = 1;
	for(j = 0; environ[i][namelen + k] != '\0'; j++)
	{
		result[j] = environ[i][namelen + k];
		k++;
	}
	return(result);
}




void main(int argc, char **argv)
{
	dir_t *head;
	head = splitdir(_getenv("PATH"));

	puts("OK1");
	while (head)
	{
		printf("%s\n", head->str);
		head = head->next;
	}
}
