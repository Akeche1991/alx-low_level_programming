#include "main.h"

/**
  * read_textfile - ...
  * @filename: The source file
  * @letters: Number of letters to reads and prints
  *
  * Return: ...
  */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fn, name;
	char *buff = malloc(sizeof(char *) * letters);

	if (!buff)
		return (0);

	if (!filename)
		return (0);

	fn = open(filename, O_RDONLY, 0600);
	if (fn == -1)
		return (0);

	name = read(fn, buff, letters);
	write(STDOUT_FILENO, buff, name);

	free(buff);
	close(fn);
	return (name);
}
