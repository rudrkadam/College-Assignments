#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#define MAX_BUFF 1024

int main()
{
    int words = 0, lines = 0, chars = 0;
    FILE *fp;   // Fil pointer - to work with a text file
    char buff[MAX_BUFF];
    int fd, fd1, i = 0;

    char *myfifo1 = "myfifo1";
    char *myfifo2 = "myfifo2";
    
    mkfifo(myfifo2, 0777);

    fd = open(myfifo1, O_RDONLY);
    read(fd, buff, MAX_BUFF);

    printf("Message received (from Pipe 1): \n%s", buff);

    // Count the words, characters and lines in the Pipe 1 message
    while (buff[i] != '\0')
    {
        if (buff[i] == ' ' || buff[i] == '\n')
        {
            words++;
        }
        else
            chars++;

        if (buff[i] == '\n')
            lines++;

        i++;
    }
    words++;
    lines++;

    printf("\n\nNumber of lines are: %d\n", lines);
    printf("Number of words are: %d\n", words);
    printf("Number of characters are: %d\n", chars);

    // Write this into a text file 'z.txt'
    fp = fopen("z.txt", "w+");
    fprintf(fp, "\nNumber of lines are: %d\n", lines);
    fprintf(fp, "Number of words are: %d\n", words);
    fprintf(fp, "Number of characters are: %d\n", chars);

    fclose(fp);
    close(fd);
    unlink(myfifo1);

    // Open 'myfifo2' in write-only mode
    fd1 = open(myfifo2, O_WRONLY);
    // System command to concatenate (cat) the 'x.txt' file to 'myfifo2' pipe
    system("cat z.txt > myfifo2");
    close(fd1);
    return 0;
}