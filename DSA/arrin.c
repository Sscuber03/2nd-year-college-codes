#include<stdio.h>
int main(){
    int k,n,l,i,a[10];
    printf("Enter number of elements in array: ");
    scanf("%d",&l);
    for(i=0;i<l;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Enter the value to be inserted: ");
    scanf("%d",&k);
    printf("Enter the position to be inserted: ");
    scanf("%d",&n);
    for(int i=l-1;i>=n-1;i--)
    {
        a[i+1]=a[i];
    }
    a[n-1]=k;
    l++;
    printf("Array after insertion: ");
    for(i=0;i<l;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
    return 0;
}
