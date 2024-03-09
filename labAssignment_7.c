#include <stdio.h>

// A function to swap two elements in an array using pointers
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
// A function to print the # of times each element was swapped and the total # of swaps
void printResult(int arr[], int carr[], int size)
{
    int i, total = 0;
    for (i = 0; i < size; i++)
    {
        printf("%d: %d\n", arr[i], carr[i]);
        total += carr[i];
    }
    printf("%d\n", total / 2);
}
// A function to implement bubble sort
void bubbleSort(int arr[], int n)
{
    int carr[] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    int i, j;

    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
                carr[j] += 1;
                carr[j + 1] += 1;
                swap(&carr[j], &carr[j + 1]);
            }
        }
    }
    printResult(arr, carr, n);
}
// A function to implement insertion sort
void selectionSort(int arr[], int n)
{
    int carr[] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    int i, j, min;
    for (i = 0; i < n - 1; i++)
    {
        min = i;
        for (j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min]) 
                min = j;
        }
        swap(&arr[i], &arr[min]);
        if (min != i) {
            carr[min] += 1;
            carr[i] += 1;
        }
        swap(&carr[i], &carr[min]);
    }
    printResult(arr, carr, n);
}
// main
int main()
{
    int array1[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int array2[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
    int n = 9;

    printf("array1 bubble sort:\n");
    bubbleSort(array1, n);
    printf("array2 bubble sort\n");
    bubbleSort(array2, n);

    int array1B[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int array2B[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
    printf("array1 selection sort:\n");
    selectionSort(array1B, n);
    printf("array2 selection sort\n");
    selectionSort(array2B, n);

    return 0;
}