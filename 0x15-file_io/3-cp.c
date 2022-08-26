#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * excode97 - checks for the correct number of arguments
 * @argc: number of arguments
 *
 * Return: void
 */
void excode97(int argc)
{
	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage: cp file_from file_to\n");
		exit(97);
	}
}

/**
 * excode98 - checks that file_from exists and can be read
 * @check: checks if true of false
 * @file: file_from name
 * @fd_from: file descriptor of file_from, or -1
 * @fd_to: file descriptor of file_to, or -1
 *
 * Return: void
 */
void excode98(long check, char *file, int fd_from, int fd_to)
{
	if (check == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", file);
		if (fd_from != -1)
			close(fd_from);
		if (fd_to != -1)
			close(fd_to);
		exit(98);
	}
}
/**
 * excode99 - checks that file_to was created and/or can be written to
 * @check: checks if true of false
 * @file: file_to name
 * @fd_from: file descriptor of file_from, or -1
 * @fd_to: file descriptor of file_to, or -1
 *
 * Return: void
 */
void excode99(long check, char *file, int fd_from, int fd_to)
{
	if (check == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't write to %s\n", file);
		if (fd_from != -1)
			close(fd_from);
		if (fd_to != -1)
			close(fd_to);
		exit(99);
	}
}
/**
 * excode100 - checks that file descriptors were closed properly
 * @check: checks if true or false
 * @fd: file descriptor
 *
 * Return: void
 */
void excode100(int check, int fd)
{
	if (check == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd);
		exit(100);
	}
}
/**
 * main - copies the content of a file to another file.
 * @argc: number of arguments passed
 * @argv: array of pointers to the arguments
 *
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	int fild_from, fild_to, close_to, close_from;
	char buffer[1024];
	long lenr, lenw;
	int file_permission;

	/*checks number of arguments*/
	excode97(argc);

	fild_from = open(argv[1], O_RDONLY);

	/*checks if files exists and can be read, code98*/
	excode98(fild_from, argv[1], -1, -1);
	file_permission = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH;
	fild_to = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, file_permission);
	/*checks if file exists and ca be read, code99*/
	excode99(fild_to, argv[2], fild_from, -1);
	lenr = 1024;
	while (lenr == 1024)
	{
		/* here we read and write*/
		lenr = read(fild_from, buffer, 1024);
		excode98(lenr, argv[1], fild_from, fild_to);
		lenw = write(fild_to, buffer, lenr);
		if (lenw != lenr)
			lenw = -1;

		excode99(lenw, argv[2], fild_from, fild_to);
	}
		/*close part*/

		close_to = close(fild_to);
		close_from = close(fild_from);

		excode100(close_to, fild_to);
		 excode100(close_from, fild_from);

	return (0);
}
