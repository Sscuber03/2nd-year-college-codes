#include<stdio.h>
#include<stdlib.h>
int main(){
    int i,n,ch,f=0;
    int k,v,p;
    int* ar;
    printf("Enter the size of the array\n");
    scanf("%d",&n);
    ar = (int*)malloc(100*sizeof(int));
    printf("Enter the elements of the array");
    for(i=0;i<n;i++)
    {
        scanf("%d",&ar[i]);
    }
    while(f==0)
    {
        printf("Enter 1 to insert, 2 to delete, 3 to print , and 4 to exit: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                printf("Enter the value to be entered: ");
                scanf("%d",&v);
                printf("Enter the position where the value is to be entered: ");
                scanf("%d",&k);
                for(i=n;i>k;i--)
                {
                    ar[i]=ar[i-1];
                }
                ar[k]=v;
                n++;
                break;
            case 2:
                printf("Enter the position to be deleted: ");
                scanf("%d",&p);
                for(i=k;i<n-1;i++)
                {
                    ar[i]=ar[i+1];
                }
                n--;
                break;
            case 3:
                printf("The array values are: \n");
                for(i=0;i<n;i++)
                {
                    printf("%d ",ar[i]);
                }
                break;
            case 4:
                f=1;
                break;
            default:
                printf("Wrong input!");
        }
    }
    return 0;
}
