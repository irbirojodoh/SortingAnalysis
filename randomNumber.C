#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generateRandomNumbersToFile(const char* filename, int count)
{
    FILE* file = fopen(filename, "w");
    if (!file)
    {
        printf("Failed to create the file: %s\n", filename);
        return;
    }

    srand((unsigned int)time(NULL));

    for (int i = 0; i < count; i++)
    {
        int randomNumber = rand() % 100000 + 1; // Generate random number between 1 and 1000
        fprintf(file, "%d\n", randomNumber);
    }

    fclose(file);
}

int main()
{
    int count;

    printf("Enter the number of random numbers to generate: ");
    scanf("%d", &count);

    generateRandomNumbersToFile("data.csv", count);

    printf("Random numbers have been generated and saved to data.csv.\n");

    return 0;
}
