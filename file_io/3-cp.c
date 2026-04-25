#include "main.h"
#include <stdio.h>

/**
 * close_error - helper function to close fd and exit on failure
 * @fd: file descriptor to close
 */
void close_error(int fd)
{
	if (close(fd) == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}

/**
 * copy_file - copies content from one fd to another
 * @fd_from: source file descriptor
 * @fd_to: destination file descriptor
 * @av: argument vector for error naming
 */
void copy_file(int fd_from, int fd_to, char **av)
{
	ssize_t n_read, n_wrote;
	char buf[1024];

	while ((n_read = read(fd_from, buf, 1024)) > 0)
	{
		n_wrote = write(fd_to, buf, n_read);
		if (n_wrote == -1 || n_wrote != n_read)
		{
			dprintf(STDERR_FILENO, "Error: Can't write to %s\n", av[2]);
			close_error(fd_from);
			close_error(fd_to);
			exit(99);
		}
	}
	if (n_read == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", av[1]);
		close_error(fd_from);
		close_error(fd_to);
		exit(98);
	}
}

/**
 * main - copies the content of a file to another file
 * @ac: argument count
 * @av: argument vector
 *
 * Return: 0 on success
 */
int main(int ac, char **av)
{
	int fd_from, fd_to;

	if (ac != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}
	fd_from = open(av[1], O_RDONLY);
	if (fd_from == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", av[1]);
		exit(98);
	}
	fd_to = open(av[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);
	if (fd_to == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", av[2]);
		close_error(fd_from);
		exit(99);
	}
	copy_file(fd_from, fd_to, av);
	close_error(fd_from);
	close_error(fd_to);
	return (0);
}
