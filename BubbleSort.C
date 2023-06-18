#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_LINE_LENGTH 100
#define MAX_ARRAY_SIZE 100000000

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int array[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                swap(&array[j], &array[j + 1]);
            }
        }
    }
}

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

        if (index >= MAX_ARRAY_SIZE)
        {
            printf("Exceeded maximum array size\n");
            break;
        }
    }

    fclose(file);
    return index;
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
    bubbleSort(numbers, count);
    clock_t end = clock();
    double elapsedTime = (double)(end - start) / CLOCKS_PER_SEC;

    // printf("Sorted array: ");
    // for (int i = 0; i < count; i++)
    // {
    //     printf("%d ", numbers[i]);
    // }
    printf("\n");

    printf("Time taken to sort using BubbleSort: %.10f seconds.\n", elapsedTime);

    free(numbers);

    return 0;
}
