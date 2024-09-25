#include "get_next_line.h"
#include <stdio.h>

int main(void)
{
    int fd;
    char *line;

    // Open a file to test reading from it
    fd = open("test.txt", O_RDONLY);
    if (fd < 0)
    {
        write(2,"Error opening file",19);
        return (1);
    }

    // Read and print lines until EOF
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }

    // Close the file
    close(fd);
    return (0);
}
