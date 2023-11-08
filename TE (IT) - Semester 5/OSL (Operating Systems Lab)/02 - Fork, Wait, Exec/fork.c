#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main()
{
    int choice;
    printf("\n1 - Fork & Wait\n");
    printf("2 - Orphan Process\n");
    printf("3 - Zombie Process\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    // FORK & WAIT
    case 1:
    {
        pid_t pid = fork();

        if (pid < 0)
        {
            printf("Fork failed.\n");
            exit(1);
        }
        else if (pid == 0)
        {
            // Child process

            // Show the process list
            printf("\n");
            system("ps");

            printf("\nChild process started.\n");
            printf("Child process PID: %d\n", getpid());
            printf("Parent process PID: %d\n", getppid());
            printf("\n⇒ CHILD PROCESS HAS TERMINATED.\n");
        }
        else
        {
            // Parent process

            printf("\nParent process (with PID %d) started and is waiting \nfor the child process to get terminated.\n", getpid());

            // wait function makes the parent process wait till the completition of it's child process
            wait(NULL);

            // Show the process list
            printf("\n");
            system("ps");

            printf("\nParent process continues execution.\n");
            printf("Parent process PID: %d\n", getpid());
            printf("Child process (already terminated) PID: %d\n", pid);
            printf("\n⇒ PARENT PROCESS HAS TERMINATED.\n");
        }
        break;
    }

    // ORPHAN PROCESS
    case 2:
    {
        pid_t pid = fork();

        if (pid < 0)
        {
            printf("Fork failed.\n");
            exit(1);
        }
        else if (pid == 0)
        {
            // Child process - Orphan

            // This sleep is to allow parent process to execute first
            sleep(3);

            printf("\nChild process started.\n");
            printf("Child process PID: %d\n", getpid());
            printf("Parent process PID: %d\n", getppid());
            printf("\n⇒ CHILD PROCESS NOW SLEEPS FOR 10 SEC.\n");

            // Show the process list
            printf("\n");
            system("ps");

            sleep(10);

            printf("\nChild process continues execution. \nBut now it has become an orphan process.\n");
            printf("\n⇒ CHILD PROCESS HAS TERMINATED.\n");

            // Show the process list
            printf("\n");
            system("ps");
        }
        else
        {
            // Parent Process

            printf("\nParent process (with PID %d) started and will sleep \nfor 5 sec for the child process to get started.\n", getpid());

            // Show the process list
            printf("\n");
            system("ps");
            sleep(5);

            printf("\nParent process continues execution.\n");
            printf("Parent process PID: %d\n", getpid());
            printf("Child process PID: %d\n", pid);
            printf("\n⇒ PARENT PROCESS HAS TERMINATED.\n");
        }
        break;
    }

    // ZOMBIE PROCESS
    case 3:
    {
        pid_t pid = fork();

        if (pid < 0)
        {
            printf("Fork failed.\n");
            exit(1);
        }
        else if (pid == 0)
        {
            // Child process - Zombie

            // This sleep is to allow parent process to execute first
            sleep(3);

            printf("\nChild process started.\n");
            printf("Child process PID: %d\n", getpid());
            printf("Parent process PID: %d\n", getppid());

            // Show the process list
            printf("\n");
            system("ps");

            printf("\n⇒ CHILD PROCESS HAS TERMINATED WITHOUT GIVING \nITS EXIT STATUS TO ITS PARENT.\n");
            printf("THUS IT WILL BECOME A ZOMBIE PROCESS.\n");
        }
        else
        {
            // Parent Process

            printf("\nParent process (with PID %d) started and will sleep \nfor 10 sec for the child process to get executed.\n", getpid());

            // Show the process list
            printf("\n");
            system("ps");

            // Sleep to allow the child process to terminate first
            sleep(10);

            printf("\nParent process continues execution.\n");
            printf("Parent process PID: %d\n", getpid());
            printf("Child process (now Zombie) PID: %d\n", pid);
            printf("\n⇒ PARENT PROCESS HAS TERMINATED WITHOUT COLLECTING \nTHE EXIT STATUS OF ITS CHILD PROCESS.\n");
            printf("HENCE THERE IS A ZOMBIE PROCESS IN THE PROCESS LIST:\n");

            // Show the process list
            printf("\n");
            system("ps");
        }
        break;
    }
    default:
        printf("Invalid choice.\n");
        break;
    }

    return 0;
}