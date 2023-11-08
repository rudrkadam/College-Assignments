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
    
    // Get shared memory segment
    shmid = shmget((key_t)1234, 1024, 0666);

    printf("\nCLIENT PROCESS (PID: %d)\n", getpid());
    printf("\nKey of shared memory is %d\n", shmid);
    
    // Attaching process to the shared memory segment
    shared_memory = shmat(shmid, NULL, 0);

    printf("Process attached at %p\n", shared_memory);
    printf("\nData read from the shared memory:\n%s", (char *)shared_memory);
}