#include<stdio.h>
#include<stdlib.h>
int main()
{
	int r,c,i,j,v=0;
	printf("Enter number of rows: ");
	scanf("%d",&r);
	printf("Enter number of columns: ");
	scanf("%d",&c);
	int** arr = (int**)malloc(r*sizeof(int*));
	for(i=0;i<r;i++)
	{
		arr[i] = (int*)malloc(c*sizeof(int));
	}
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			arr[i][j]=++v;
		}
	}
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			printf("%d ",arr[i][j]);
		}
		printf("\n");
	}
	return 0;
}
