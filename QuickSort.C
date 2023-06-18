#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LINE_LENGTH 100
#define MAX_ARRAY_SIZE 100000000

int readCSV(const char *filename, int array[])
{
    FILE *file = fopen(filename, "r");
    if (!file)
    {
        printf("Failed to open the file: %s\n", filename);
        return -1;
    }

    char line[MAX_LINE_LENGTH];
    int index = 0;

    while (fgets(line, MAX_LINE_LENGTH, file))
    {
        array[index] = atoi(line);
        index++;
    }

    fclose(file);
    return index;
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int array[], int low, int high)
{
    int pivot = array[low];
    int i = low - 1;
    int j = high + 1;

    while (1)
    {
        do
        {
            i++;
        } while (array[i] < pivot);

        do
        {
            j--;
        } while (array[j] > pivot);

        if (i < j)
        {
            swap(&array[i], &array[j]);
        }
        else
        {
            return j;
        }
    }
}

void quicksort(int array[], int low, int high)
{
    if (low < high)
    {
        int pivotIndex = partition(array, low, high);
        quicksort(array, low, pivotIndex);
        quicksort(array, pivotIndex + 1, high);
    }
}

int main()
{
        const char *filename = "data.csv";
int *numbers = (int *)malloc(MAX_ARRAY_SIZE * sizeof(int));
    if (numbers == NULL)
    {
        printf("Failed to allocate memory for the array\n");
        return 1;
    }

    int count = readCSV(filename, numbers);

    if (count == -1)
    {
        free(numbers);
        return 1;
    }



    clock_t start = clock();
    quicksort(numbers, 0, count - 1);
    clock_t end = clock();
    double elapsedTime = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Time taken to sort using QuickSort: %.10f seconds.\n", elapsedTime);

    return 0;
}
