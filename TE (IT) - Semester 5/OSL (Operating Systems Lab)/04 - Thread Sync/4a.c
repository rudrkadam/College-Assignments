#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <time.h>

#define BUFFER_SIZE 5
#define NUM_PRODUCERS 3
#define NUM_CONSUMERS 2

int buffer[BUFFER_SIZE];        // Array representing the shared buffer
sem_t empty, full, mutex;       // Semaphores for synchronization

// Indices used to keep track of where to add or remove items from the buffer
int in = 0;
int out = 0;

// Producer thread function
void *producer(void *arg)
{
    int item;
    while (1)   // Infinite loop, producing items and adding them to the shared buffer
    {
        item = rand() % 100;    // Produce an item (like a random no. between 0 and 99)

        // wait decrements the value
        sem_wait(&empty);       // Decrements 'empty' and waits till 'empty' > 0
        sem_wait(&mutex);       // Locks the buffer (1 becomes 0)

        /* CRITICAL SECTION */
        buffer[in] = item;      // Enter the items in the buffer
        printf("Producer %d produced item: %d\n", *((int *)arg), item);
        in = (in + 1) % BUFFER_SIZE;    // Updates the value of 'in' in a circular buffer
        /* CRITICAL SECTION */

        // signal or post increments the value
        sem_post(&mutex);       // Unlocks the buffer (0 becomes 1 again)
        sem_post(&full);        // Increments 'full' indicating that a new item is available for consumption

        sleep(1);               // Simulate slower producer
    }
    pthread_exit(NULL);
}

// Consumer thread function
void *consumer(void *arg)
{
    int item;
    while (1)
    {
        sem_wait(&full);        // Decrements 'full' and waits till 'full' > 0
        sem_wait(&mutex);       // Locks the buffer (1 becomes 0)

        /* CRITICAL SECTION */
        item = buffer[out];     // Consume the items from the buffer
        printf("Consumer %d consumed item: %d\n", *((int *)arg), item);
        out = (out + 1) % BUFFER_SIZE;
        /* CRITICAL SECTION */

        sem_post(&mutex);       // Unlocks the buffer (0 becomes 1)
        sem_post(&empty);       // Increments 'empty' indicating there's an empty slot in the buffer for producers to fill

        sleep(2);               // Simulate slower consumer
    }
    pthread_exit(NULL);
}

int main()
{
    // Arrays to store thread IDs for producer and consumer threads
    pthread_t producers[NUM_PRODUCERS];
    pthread_t consumers[NUM_CONSUMERS];

    // Arrays to hold unique identifiers for each producer and consumer thread
    int producer_ids[NUM_PRODUCERS];
    int consumer_ids[NUM_CONSUMERS];

    // Initializes the 'empty' semaphore with an initial value of 'BUFFER_SIZE'
    sem_init(&empty, 0, BUFFER_SIZE);
    // Initializes the 'full' semaphore with an initial value of 0
    sem_init(&full, 0, 0);
    // Initializes the 'mutex' semaphore with an initial value of 1
    sem_init(&mutex, 0, 1);

    // Creating and starting the producer threads
    for (int i = 0; i < NUM_PRODUCERS; i++)
    {
        producer_ids[i] = i + 1;
        pthread_create(&producers[i], NULL, producer, &producer_ids[i]);
    }

    // Creating and starting the consumer threads
    for (int i = 0; i < NUM_CONSUMERS; i++)
    {
        consumer_ids[i] = i + 1;
        pthread_create(&consumers[i], NULL, consumer, &consumer_ids[i]);
    }

    while (1)
    {
        // The main thread can perform other tasks or have additional control logic here.
        // For simplicity, we just let the producer and consumer threads run indefinitely.
    }

    // Release the resources associated with the semaphores when the program terminates,
    // unreachable in the current code because the program has an infinite loop.
    sem_destroy(&empty);
    sem_destroy(&full);
    sem_destroy(&mutex);

    return 0;
}