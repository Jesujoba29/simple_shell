#include "shell.h"

/**
 * bfree - Free address
 * @ptr: Points to address free
 *
 * Return: if 1 freed if otherwise 0.
 */
int bfree(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}

