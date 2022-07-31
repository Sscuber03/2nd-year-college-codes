#include<stdio.h>
#include<stdlib.h>
int main(){
    int i,n;
    int* ar;
    printf("Enter the size of the array\n");
    scanf("%d",&n);
    ar = (int*)malloc(n*sizeof(int));
    printf("Enter the elements of the array");
    for(i=0;i<n;i++)
    {
        scanf("%d",&ar[i]);
    }
    printf("The array elements are: ");
    for(i=0;i<n;i++)
    {
        printf("%d ",ar[i]);
    }
    return 0;
}
