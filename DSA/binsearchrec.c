#include <stdio.h>
#include <stdlib.h>

int binarySearch(int arr[], int l, int r, int k)
{
    int mid;
    if (l <= r)
    {
        mid = (l + r) / 2;
        if (arr[mid] == k)
            return mid;
        else if (arr[mid] > k)
            binarySearch(arr, l, mid - 1, k);
        else
            binarySearch(arr, mid + 1, r, k);
    }
    else
        return -1;
}

int main()
{
    int n, target;
    printf("Enter size of array:");
    scanf("%d", &n);
    int *arr;
    arr = (int *)malloc(sizeof(int) * n);
    int i;
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter target element to search:");
    scanf("%d", &target);
    int res;
    res = binarySearch(arr, 0, n - 1, target);
    if (res != -1)
        printf("The target found at position %d.", res);
    else
        printf("The target is not found in the array.");
}