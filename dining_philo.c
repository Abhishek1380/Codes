#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define NUM_PHILOSOPHERS 5

sem_t chopsticks[NUM_PHILOSOPHERS];
sem_t mutex;

void *philosopher(void *arg);
void think(int index);
void eat(int index);

int main()
{
    srand(time(NULL));

    pthread_t philosophers[NUM_PHILOSOPHERS];
    int indices[NUM_PHILOSOPHERS];

    sem_init(&mutex, 0, 1);

    for (int i = 0; i < NUM_PHILOSOPHERS; i++)
    {
        sem_init(&chopsticks[i], 0, 1);
    }

    for (int i = 0; i < NUM_PHILOSOPHERS; i++)
    {
        indices[i] = i;
        pthread_create(&philosophers[i], NULL, philosopher, (void *)&indices[i]);
    }

    for (int i = 0; i < NUM_PHILOSOPHERS; i++)
    {
        pthread_join(philosophers[i], NULL);
    }

    for (int i = 0; i < NUM_PHILOSOPHERS; i++)
    {
        sem_destroy(&chopsticks[i]);
    }

    sem_destroy(&mutex);

    return 0;
}

void *philosopher(void *arg)
{
    int index = *((int *)arg);

    while (1)
    {
        think(index);

        sem_wait(&mutex);
        sem_wait(&chopsticks[index]);
        sem_wait(&chopsticks[(index + 1) % NUM_PHILOSOPHERS]);
        sem_post(&mutex);

        eat(index);

        sem_post(&chopsticks[index]);
        sem_post(&chopsticks[(index + 1) % NUM_PHILOSOPHERS]);
    }

    return NULL;
}

void think(int index)
{
    printf("Philosopher %d is thinking\n", index);
    usleep(rand() % 2000000 + 1000000); // Sleep for 1 to 3 seconds
}

void eat(int index)
{
    printf("Philosopher %d is eating\n", index);
    usleep(rand() % 2000000 + 1000000); // Sleep for 1 to 3 seconds
}
