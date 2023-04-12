#include <stdio.h>
#include "main.h"

/**
  * append_text_to_file - ...
  * @filename: ...
  * @text_content: ...
  *
  * Return: ...
  */
int append_text_to_file(const char *filename, char *text_content)
{
	int fn;

	if (!filename)
		return (-1);

	fn = open(filename, O_WRONLY | O_APPEND);
	if (fn == -1)
		return (-1);

	if (text_content)
	{
		if (write(fn, text_content, _strlen(text_content)) == -1)
			return (-1);
	}

	close(fn);
	return (1);
}

/**
  * _strlen - Returns the length of a string
  * @s: String to count
  *
  * Return: String length
  */
int _strlen(char *s)
{
	int c = 0;

	while (s[c])
		c++;

	return (c);
}
