#include "main.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

/**
 * create_file - creates a file and writes text_content to it
 * @filename: name of the file to create
 * @text_content: NULL-terminated string to write in the file
 *
 * Return: 1 on success, -1 on failure
 */
int create_file(const char *filename, char *text_content)
{
int fd;
ssize_t to_write, written;
size_t len = 0;

if (filename == NULL)
return (-1);

if (text_content != NULL)
len = strlen(text_content);

fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR);
if (fd == -1)
return (-1);

to_write = (ssize_t)len;
while (to_write > 0)
{
written = write(fd, text_content + (len - to_write), to_write);
if (written == -1)
{
close(fd);
return (-1);
}
to_write -= written;
}

if (close(fd) == -1)
return (-1);

return (1);
}
