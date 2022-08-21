#include<stdio.h>
#include<stdlib.h>
int main()
{
	int r,i,j,v=0;
	printf("Enter number of rows: ");
	scanf("%d",&r);
	int* c = (int*)malloc(r*sizeof(int));
	printf("Enter number of columns for each row: \n");
	for(i=0;i<r;i++)
	{
		scanf("%d",&c[i]);
	}
	int** arr = (int**)malloc(r*sizeof(int*));
	for(i=0;i<r;i++)
	{
		arr[i] = (int*)malloc(c[i]*sizeof(int));
	}
	for(i=0;i<r;i++)
	{
		for(j=0;j<c[i];j++)
		{
			arr[i][j]=++v;
		}
	}
	printf("Final matrix: \n");
	for(i=0;i<r;i++)
	{
		for(j=0;j<c[i];j++)
		{
			printf("%d ",arr[i][j]);
		}
		printf("\n");
	}
	return 0;
}
