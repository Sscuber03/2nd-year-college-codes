#include<stdio.h>
int main(){
    int k,n,i,a[10];
    printf("Enter the size of the array");
    scanf("%d",&n);
    printf("Enter the array elements: ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Enter the position to be deleted: ");
    scanf("%d",&k);
    for(i=k;i<n-1;i++)
    {
        a[i]=a[i+1];
    }
    n--;
    printf("Array after deletion: ");
    for(i=0;i<n;i++)
    {
        printf("%d",a[i]);
    }
    printf("\n");
    return 0;
}
