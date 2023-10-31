#include "main.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * read_textfile - reads a text file and prints the character
 * @filename: filename.
 * @letters: numbers of letters printed.
 * Return: Return number of character printed else 0
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	ssize_t rdn, wrn;
	int fn;
	char *buffer;

	if (!filename)
		return (0);

	fn = open(filename, O_RDONLY);

	if (fn == -1)
		return (0);

	buffer = malloc(sizeof(char) * (letters));
	if (!buffer)
		return (0);

	rdn = read(fn, buffer, letters);
	wrn = write(STDOUT_FILENO, buffer, rdn);

	close(fn);

	free(buffer);

	return (wrn);
}
