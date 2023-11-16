#include "shell.h"

/**
 * list_len - linked list size
 * @h: Header to first node
 *
 * Return: Lists size
 */
size_t list_len(const list_t *h)
{
	size_t i = 0;

	while (h)
	{
		h = h->next;
		i++;
	}
	return (i);
}

/**
 * list_to_strings - Of array of linked lists
 * @head: first node
 *
 * Return: String array
 */
char **list_to_strings(list_t *head)
{
	list_t *node = head;
	size_t i = list_len(head), t
	char **strs;
	char *str;

	if (!head || !i)
		return (NULL);
	strs = malloc(sizeof(char *) * (i + 1));
	if (!strs)
		return (NULL);
	for (i = 0; node; node = node->next, i++)
	{
		str = malloc(_strlen(node->str) + 1);
		if (!str)
		{
			for (t = 0; t < i; t++)
				free(strs[t]);
			free(strs);
			return (NULL);
		}

		str = _strcpy(str, node->str);
		strs[i] = str;
	}
	strs[i] = NULL;
	return (strs);
}


/**
 * print_list - Print linked list
 * @h:first node
 *
 * Return: list size
 */
size_t print_list(const list_t *h)
{
	size_t i = 0;

	while (h)
	{
		_puts(convert_number(h->num, 10, 0));
		_putchar(':');
		_putchar(' ');
		_puts(h->str ? h->str : "(nil)");
		_puts("\n");
		h = h->next;
		i++;
	}
	return (i);
}

/**
 * node_starts_with - node return whose string starts
 * @node:list head
 * @prefix: string
 * @c: character match
 *
 * Return: 0 or node
 */
list_t *node_starts_with(list_t *node, char *prefix, char c)
{
	char *a = NULL;

	while (node)
	{
		a = starts_with(node->str, prefix);
		if (a && ((c == -1) || (*a == c)))
			return (node);
		node = node->next;
	}
	return (NULL);
}

/**
 * get_node_index - The index of a node
 * @head:  list head
 * @node:  the node
 *
 * Return: if -1  next node
 */
ssize_t get_node_index(list_t *head, list_t *node)
{
	size_t i = 0;

	while (head)
	{
		if (head == node)
			return (i);
		head = head->next;
		i++;
	}
	return (-1);
}

