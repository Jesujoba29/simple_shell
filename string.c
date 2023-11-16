#include "shell.h"

/**
 * _strlen - Checks for the string length
 * @s: Stringd
 *
 * Return: Value of string length
 */
int _strlen(char *s)
{
	int a = 0;

	if (!s)
		return (0);

	while (*s++)
		a++;
	return (a);
}

/**
 * _strcmp - Check for string comparison
 * @s1: String one
 * @s2: String two
 *
 * Return: If negative s1 < s2  If positive s1 > s2
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	if (*s1 == *s2)
		return (0);
	else
		return (*s1 < *s2 ? -1 : 1);
}

/**
 * starts_with - Haystack checking
 * @haystack: Searching for a string
 * @needle: Needle
 *
 * Return: The address or NULL
 */
char *starts_with(const char *haystack, const char *needle)
{
	while (*needle)
		if (*needle++ != *haystack++)
			return (NULL);
	return ((char *)haystack);
}

/**
 * _strcat - String catenation
 * @dest: The destination
 * @src: It source
 *
 * Return: Destination of the buffer
 */
char *_strcat(char *dest, char *src)
{
	char *ret = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = *src;
	return (ret);
}

