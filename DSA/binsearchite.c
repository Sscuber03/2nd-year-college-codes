#include <stdio.h>

int bSearch(int array[], int start, int end, int ele)
{
    while (start <= end)
    {
        int middle = start + (end - start) / 2;
        if (array[middle] == ele)
            return middle;
        if (array[middle] < ele)
            start = middle + 1;
        else
            end = middle - 1;
    }
    return -1;
}
int main()
{
    int array[] = {1, 4, 7, 9, 16, 56, 70};
    int n = 7;
    int ele = 16;
    int found = bSearch(array, 0, n - 1, ele);
    if (found == -1)
    {
        printf("Element not found in the array ");
    }
    else
    {
        printf("Element found at index : %d", found);
    }
    return 0;
}