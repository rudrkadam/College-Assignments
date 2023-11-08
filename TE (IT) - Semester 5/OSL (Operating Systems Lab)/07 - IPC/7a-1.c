#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#define MAX_BUFF 1024

int main()
{
    // Declare integer variables for file descriptors and iterator
    int fd1, fd2, i = 0;

    // Defining character pointers for fifo names
    char *myfifo1 = "myfifo1";
    char *myfifo2 = "myfifo2";

    char buff[MAX_BUFF];    // Character array to store the input string
    char str;               // Character variable to read characters
    int res;

    res = mkfifo(myfifo1, 0777);
    if (res == -1)
    {
        printf("\nPipe 1 not created.");
        return 0;
    }

    printf("Enter a string (use # to terminate the string):\n");
    while ((str = getchar()) != '#')
        buff[i++] = str;
    buff[i] = '\0';         // Null-terminate the 'buff' array

    // Open 'myfifo1' in write-only mode
    fd1 = open(myfifo1, O_WRONLY);
    write(fd1, buff, sizeof(buff));
    close(fd1);

    // Open 'myfifo2' in read-only mode
    fd2 = open(myfifo2, O_RDONLY);
    read(fd2, &buff, MAX_BUFF);

    printf("\nContents of files (from Pipe 2): %s", buff);
    close(fd2);

    unlink(myfifo1);
    unlink(myfifo2);

    return 0;
}