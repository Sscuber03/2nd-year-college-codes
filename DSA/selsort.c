#include <stdio.h>
#include <stdlib.h>

int selectele(int *arr, int i, int n)
{
    int min_index = i, j;
    for (j = i + 1; j < n; j++)
    {
        if (arr[min_index] > arr[j])
        {
            min_index = j;
        }
    }
    return min_index;
}

void selectionSort(int arr[], int n)
{
    int i, selected_index, temp;
    for (i = 0; i < n - 1; i++)
    {
        selected_index = selectele(arr, i, n);
        temp = arr[i];
        arr[i] = arr[selected_index];
        arr[selected_index] = temp;
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
    selectionSort(arr, size);
    printar(arr, size);
    return 0;
}