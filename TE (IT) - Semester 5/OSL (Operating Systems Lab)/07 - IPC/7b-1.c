#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/shm.h>
#include <string.h>

int main()
{
    int i;
    void *shared_memory;
    char buff[20];
    int shmid;

    /*
    creates shared memory segment with key 1234, having size 1024 bytes.
    IPC_CREAT is used to create the shared segment if it does not exist.
    0666 are the permisions on the shared segment
    */
    shmid = shmget((key_t)1234, 1024, 0666 | IPC_CREAT);
    
    printf("\nSERVER PROCESS (PID: %d)\n", getpid());
    printf("\nKey of shared memory is %d\n", shmid);
    
    // Attaching process to the shared memory segment
    shared_memory = shmat(shmid, NULL, 0);

    // Print the address where the segment is attached with this process
    printf("Process attached at %p\n", shared_memory);
    
    printf("\nEnter some data to write to the shared memory:\n");
    
    // Read data from stdin
    read(0, buff, 20);
    buff[19] = '\0';    // Null-terminate the input data

    // Copy data from buff to shared memory, limiting to 1023 characters
    strncpy(shared_memory, buff, 1023);

    printf("\nData entered in shared memory:\n%s", (char*)shared_memory);
}