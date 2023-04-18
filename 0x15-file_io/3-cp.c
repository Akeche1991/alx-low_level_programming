#include <stdio.h>
#include "main.h"

/**
  * main - Entry point
  * @argc: The argument count
  * @argv: The argument vector
  *
  * Return: ...
  */
int main(int argc, char **argv)
{
	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}

	copy_file(argv[1], argv[2]);
	exit(0);
}

/**
  * copy_file - ...
  * @src: ...
  * @dest: ...
  *
  * Return: ...
  */
void copy_file(const char *src, const char *dest)
{
	int ofn, tfn, readed;
	char buff[1024];

	ofn = open(src, O_RDONLY);
	if (!src || ofn == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", src);
		exit(98);
	}

	tfn = open(dest, O_CREAT | O_WRONLY | O_TRUNC, 0664);
	while ((readed = read(ofn, buff, 1024)) > 0)
	{
		if (write(tfn, buff, readed) != readed || tfn == -1)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", dest);
			exit(99);
		}
	}

	if (readed == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", src);
		exit(98);
	}

	if (close(ofn) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fn %d\n", ofn);
		exit(100);
	}

	if (close(tfn) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fn %d\n", tfn);
		exit(100);
	}
}
