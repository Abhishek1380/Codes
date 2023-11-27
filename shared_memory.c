#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>

#define SHM_SIZE 1024

int main()
{
    key_t key = ftok("shared_memory_example", 65); // Generate a key

    // Create a shared memory segment
    int shmid = shmget(key, SHM_SIZE, IPC_CREAT | 0666);
    if (shmid == -1)
    {
        perror("shmget");
        exit(EXIT_FAILURE);
    }

    // Attach the shared memory segment to the address space
    char *shmaddr = shmat(shmid, NULL, 0);
    if (shmaddr == (char *)-1)
    {
        perror("shmat");
        exit(EXIT_FAILURE);
    }

    // Write a message to the shared memory
    strcpy(shmaddr, "Hello from the server!");

    printf("Server: Message written to shared memory\n");

    // Detach the shared memory segment
    if (shmdt(shmaddr) == -1)
    {
        perror("shmdt");
        exit(EXIT_FAILURE);
    }

    return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>

#define SHM_SIZE 1024

int main()
{
    key_t key = ftok("shared_memory_example", 65); // Use the same key as the server

    // Locate the shared memory segment
    int shmid = shmget(key, SHM_SIZE, 0666);
    if (shmid == -1)
    {
        perror("shmget");
        exit(EXIT_FAILURE);
    }

    // Attach the shared memory segment to the address space
    char *shmaddr = shmat(shmid, NULL, 0);
    if (shmaddr == (char *)-1)
    {
        perror("shmat");
        exit(EXIT_FAILURE);
    }

    // Read and display the message from shared memory
    printf("Client: Message received from server: %s\n", shmaddr);

    // Detach the shared memory segment
    if (shmdt(shmaddr) == -1)
    {
        perror("shmdt");
        exit(EXIT_FAILURE);
    }

    // Remove the shared memory segment (optional, comment out if not needed)
    if (shmctl(shmid, IPC_RMID, NULL) == -1)
    {
        perror("shmctl");
        exit(EXIT_FAILURE);
    }

    return 0;
}
