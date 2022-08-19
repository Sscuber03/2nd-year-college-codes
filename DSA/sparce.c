#include<stdio.h>
#include<stdlib.h>
int main()
{
	int r,c,i,j,count=0;
	int index=0;
	printf("Enter the number of rows: ");
	scanf("%d",&r);
	printf("Enter the number of colimns: ");
	scanf("%d",&c);
	int** arr = (int**)malloc(r*sizeof(int*));
	for(i=0;i<r;i++)
	{
		arr[i] = (int*)malloc(c*sizeof(int));
	}
	printf("Enter the array elements: \n");
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			scanf("%d",&arr[i][j]);
			if(arr[i][j]!=0)
				count++;
		}
	}
	int** sprarr = (int**)malloc((count+1)*sizeof(int*));
	for(i=0;i<=count;i++)
	{
		sprarr[i] = (int*)malloc(3*sizeof(int));
	}
	sprarr[index][0]=r;
	sprarr[index][1]=c;
	sprarr[index][2]=count;
	index++;
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			if(arr[i][j]!=0)
			{
				sprarr[index][0]=i;
				sprarr[index][1]=j;
				sprarr[index][2]=arr[i][j];
				index++;
			}
		}
	}
	for(i=0;i<index;i++)
	{
		for(j=0;j<3;j++)
		{
			printf("%d ",sprarr[i][j]);
		}
		printf("\n");
	}
	return 0;
}
