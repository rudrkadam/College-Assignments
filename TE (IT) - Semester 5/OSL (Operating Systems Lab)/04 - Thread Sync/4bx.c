#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define NUM_READERS 3
#define NUM_WRITERS 2

sem_t mutex, wrt;
int readcount = 0;

// Writer thread function
void *writer_thr(void *arg)
{
    int id = *((int *)arg);
    
    printf("\nWriter %d is trying to enter the database for modifying data.\n", id);
    sem_wait(&wrt);         // Decrement 'wrt' - only one writer can enter the critical section at a time

    /* CRITICAL SECTION */
    printf("\nWriter %d is writing in the database.\n", id);
    sleep(2);               // Simulate writing process
    printf("\nWriter %d is leaving the database.\n", id);
    /* CRITICAL SECTION */

    sem_post(&wrt);         // Increment 'wrt'
    pthread_exit(NULL);     // Writer thread exits
}

// Reader thread function
void *reader_thr(void *arg)
{
    int id = *((int *)arg);

    printf("\nReader %d is trying to enter the database for reading.\n", id);
    
    sem_wait(&mutex);       // Mutual exclusion while accessing the 'readcount' variable
    readcount++;            // CRITICAL SECTION //
    if (readcount == 1)
        sem_wait(&wrt);     // Lock for writer to enter - reader priority
    sem_post(&mutex);       // Other readers can enter

    /* CRITICAL SECTION */
    printf("\nReader %d is now reading in the database.\n", id);
    /* CRITICAL SECTION */

    sem_wait(&mutex);       // Mutual exclusion while accessing the 'readcount' variable
    readcount--;            // CRITICAL SECTION //
    if (readcount == 0)
        sem_post(&wrt);     // Unlock for writer to enter
    sem_post(&mutex);       // Other readers can enter

    printf("\nReader %d has left the database.\n", id);
    sleep(2);
    pthread_exit(NULL);     // Reader thread exits
}

int main()
{
    // Arrays to store thread IDs for reader and writer threads
    pthread_t readers[NUM_READERS];
    pthread_t writers[NUM_WRITERS];

    // Arrays to hold unique identifiers for each reader and writer thread
    int reader_ids[NUM_READERS];
    int writer_ids[NUM_WRITERS];

    // Initialize the 'mutex' and 'wrt' semaphore with an initial values of 1
    sem_init(&mutex, 0, 1);
    sem_init(&wrt, 0, 1);

    for (int i = 0; i <= NUM_WRITERS; i++)
    {
        writer_ids[i] = i + 1;
        pthread_create(&writers[i], NULL, writer_thr, &writer_ids[i]);
    }

    for (int i = 0; i <= NUM_READERS; i++)
    {
        reader_ids[i] = i + 1;
        pthread_create(&readers[i], NULL, reader_thr, &reader_ids[i]);
    }

    // pthread_join function is used to wait for a specific thread
    // to finish its execution before the calling thread continues its own execution.
    for (int i = 1; i <= NUM_WRITERS; i++)
    {
        pthread_join(writers[i], NULL);
    }
    for (int i = 1; i <= NUM_READERS; i++)
    {
        pthread_join(readers[i], NULL);
    }

    sem_destroy(&wrt);
    sem_destroy(&mutex);

    pthread_exit(NULL);     // Exit the main thread
}