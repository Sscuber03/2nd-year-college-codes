#include <stdio.h>
#include <stdlib.h>

void insertionSort(int arr[], int n)
{
    int i, val, h;
    for (i = 1; i < n; i++)
    {
        val = arr[i];
        h = i;
        while (h > 0 && arr[h - 1] > val)
        {
            arr[h] = arr[h - 1];
            h--;
        }
        arr[h] = val;
    }
}

void printar(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
}

int main()
{
    int size, *arr, i;
    printf("Enter number of elements: ");
    scanf("%d", &size);
    arr = (int *)malloc(size * sizeof(int));
    for (i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
    insertionSort(arr, size);
    printar(arr, size);
    return 0;
}