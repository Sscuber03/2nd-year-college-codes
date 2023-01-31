#include <stdio.h>
#include <stdlib.h>

int interpolationSearch(int arr[], int l, int h, int target)
{
    int pos;
    while (l <= h && target >= arr[l] && target <= arr[h])
    {
        if (l == h)
        {
            if (arr[l] == target)
                return l;
            return -1;
        }
        pos = l + ((target - arr[l]) / (arr[h] - arr[l])) * (h - l);
        if (arr[pos] == target)
            return pos;
        else if (arr[pos] > target)
            h = pos - 1;
        else
            l = pos + 1;
    }
    return -1;
}

int main()
{
    int size, target;
    printf("Enter the size of the array:");
    scanf("%d", &size);
    int *arr = (int *)malloc(size * (sizeof(int)));
    printf("Enter elements:");
    for (int i = 0; i < size; i++)
        scanf("%d", &arr[i]);
    printf("Enter the target element:");
    scanf("%d", &target);
    int indx = interpolationSearch(arr, 0, size - 1, target);
    if (indx != -1)
        printf("The target element is found at index %d", indx);
    else
        printf("Target not found!");
}