#include "shell.h"

/**
 *_eputs - input string
 * @str: Print string
 *
 * Return: 0
 */
void _eputs(char *str)
{
	int a = 0;

	if (!str)
		return;
	while (str[a] != '\0')
	{
		_eputchar(str[a]);
		a++;
	}
}

/**
 * _eputchar - Write to char value
 * @c: Character
 *
 * Return: If success 1 if 0 error
 */
int _eputchar(char c)
{
	static int a;
	static char buf[WRITE_BUF_SIZE];

	if (a == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(2, buf, i);
		i = 0;
	}
	if (a != BUF_FLUSH)
		buf[i++] = a;
	return (1);
}

/**
 * _putfd - Input file description
 * @c: The character
 * @fd: Write the file descriptor
 *
 * Return: If 1 success
 */
int _putfd(char c, int fd)
{
	static int a;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || a >= WRITE_BUF_SIZE)
	{
		write(fd, buf, a);
		a = 0;
	}
	if (c != BUF_FLUSH)
		buf[a++] = c;
	return (1);
}

/**
 *_putsfd - Input string
 * @str: Print string
 * @fd: Describe file
 *
 * Return: Char number
 */
int _putsfd(char *str, int fd)
{
	int a = 0;

	if (!str)
		return (0);
	while (*str)
	{
		a += _putfd(*str++, fd);
	}
	return (a);
}

