#include <stdio.h>

int lsearch(int arr[], int size, int x)
{
    int rec;
    size--;
    if (size >= 0)
    {
        if (arr[size] == x)
            return size;
        else
            rec = lsearch(arr, size, x);
    }
    else
        return -1;
    return rec;
}

int main(void)
{
    int arr[] = {12, 34, 54, 2, 3};
    int size = sizeof(arr) / sizeof(arr[0]);
    int x = 3;
    int indx;
    indx = lsearch(arr, size, x);
    if (indx != -1)
        printf("Element %d is present at index %d", x, indx);
    else
        printf("Element %d is not present", x);

    return 0;
}