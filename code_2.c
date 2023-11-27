#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void merge(int A[], int start, int mid, int end)
{
    int i = start;
    int j = mid + 1;
    int k = start;
    int B[100];

    while (i <= mid && j <= end)
    {
        if (A[i] < A[j])
        {
            B[k] = A[i];
            i++;
            k++;
        }
        else
        {
            B[k] = A[j];
            j++;
            k++;
        }
    }
    while (i <= mid)
    {
        B[k] = A[i];
        i++;
        k++;
    }
    while (j <= end)
    {
        B[k] = A[j];
        j++;
        k++;
    }

    for (int i = start; i <= end; i++)
    {
        A[i] = B[i];
    }
}

void mergeSort(int A[], int start, int end)
{
    int mid;
    if (start < end)
    {
        mid = start + (end - start) / 2;
        mergeSort(A, start, mid);
        mergeSort(A, mid + 1, end);
        merge(A, start, mid, end);
    }
}

int partition(int A[], int start, int end)
{
    int pivot = A[start];
    int i = start + 1;
    int j = end;
    int temp;

    do
    {
        while (pivot <= A[i])
        {
            i++;
        }
        while (pivot > A[j])
        {
            j--;
        }
        if (A[i] > A[j])
        {
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }

    } while (i < j);

    temp = A[start];
    A[start] = A[j];
    A[j] = temp;
    return j;
}

void quickSort(int A[], int start, int end)
{
    int partitionIndex;
    if (start < end)
    {
        partitionIndex = partition(A, start, end);
        quickSort(A, start, partitionIndex);
        quickSort(A, partitionIndex + 1, end);
    }
}

int main()
{
    int arr[] = {2, 5, 4, 3, 8, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    pid_t pid = fork();

    if (pid == -1)
    {
        perror("Fork Failed");
        exit(EXIT_FAILURE);
    }
    else if (pid == 0)
    {

        printf("Child process (PID %d) sorting using quicksort\n", getpid());

        sleep(2);
        quickSort(arr, 0, n - 1);
        printf("Sorted array in child process...");
        for (int i = 0; i < n; i++)
        {
            printf("%d\t", arr[i]);
        }
        printf("\n");

        exit(EXIT_SUCCESS);
    }
    else
    {
        printf("Parent process (PID %d) sorting using merge sort", getpid());
        mergeSort(arr, 0, n - 1);
        for (int i = 0; i < n; i++)
        {
            printf("%d\t", arr[i]);
        }
        printf("\n");
        sleep(4);
        wait(NULL);
        printf("Parent Process exiting...\n");
    }

    return 0;
}