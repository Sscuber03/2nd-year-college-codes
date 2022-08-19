#include<stdio.h>
#include<stdlib.h>
int arrin(int** arr,int r,int c)
{
	int i,j;
	int count=0;
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
	return count;
}
void sprimp(int** spr, int** arr,int r,int c,int count)
{
	int index=0,i,j;
	spr[index][0]=r;
	spr[index][1]=c;
	spr[index][2]=count;
	index++;
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			if(arr[i][j]!=0)
			{
				spr[index][0]=i;
				spr[index][1]=j;
				spr[index][2]=arr[i][j];
				index++;
			}
		}
	}
}
int main()
{
	int r,co,i,j,k,count1,count2,c1,c2;
	printf("Enter the number of rows: ");
	scanf("%d",&r);
	printf("Enter the number of columns: ");
	scanf("%d",&co);
	int** arr1 = (int**)malloc(r*sizeof(int*));
	for(i=0;i<r;i++)
	{
		arr1[i] = (int*)malloc(co*sizeof(int));
	}
	count1=arrin(arr1,r,co);
	int** a = (int**)malloc((count1+1)*sizeof(int*));
	for(i=0;i<=count1;i++)
	{
		a[i] = (int*)malloc(3*sizeof(int));
	}
	sprimp(a,arr1,r,co,count1);
	int** arr2 = (int**)malloc(r*sizeof(int*));
	for(i=0;i<r;i++)
	{
		arr2[i] = (int*)malloc(co*sizeof(int));
	}
	count2=arrin(arr2,r,co);
	int** b = (int**)malloc((count2+1)*sizeof(int*));
	for(i=0;i<=count2;i++)
	{
		b[i] = (int*)malloc(3*sizeof(int));
	}
	sprimp(b,arr2,r,co,count2);
	int** c = (int**)malloc((count1+count2+1)*sizeof(int*));
	for(i=0;i<=count1+count2;i++)
	{
		c[i] = (int*)malloc(3*sizeof(int));
	}
	i=0,j=0,k=1;
	if(a[0][0]==b[0][0] || a[0][1]==b[0][1])
	{
	        c1=a[0][2];
	        c2=b[0][2];
	        c[0][0]=a[0][0];
	        c[0][1]=a[0][1];
		c[0][2]=a[0][2]+b[0][2];
	        while(i<c1 && j<c2)
	        {
			if(a[i][0]<b[j][0])//row of a less
            		{
		                c[k][0]=a[i][0];
		                c[k][1]=a[i][1];
		                c[k][2]=a[i][2];
			        k++;
			        i++;
		        }
		        else if(b[j][0]<a[i][0])//row of b less
        		{
			        c[k][0]=b[j][0];
			        c[k][1]=b[j][1];
			        c[k][2]=b[j][2];
			        k++;
			        j++;
			}
		        else if(a[i][1]<b[j][1])//column of a less
		        {
		                c[k][0]=a[i][0];
		                c[k][1]=a[i][1];
			        c[k][2]=a[i][2];
			        k++;
		                i++;
			}
		        else if(b[j][1]<a[i][1])//coulmn of b less
		        {
		                c[k][0]=b[j][0];
		                c[k][1]=b[j][1];
		                c[k][2]=b[j][2];
		                k++;
		                j++;
		        }
		        else//row and column equal, add them
		        {
		                c[k][0]=a[i][0];
		                c[k][1]=a[i][1];
		                c[k][2]=a[i][2]+b[j][2];
		                k++;
		                i++;
		                j++;
         		}
	        }
        	while(i<c1)//rest of first matrix
	        {
		        c[k][0]=a[i][0];
		        c[k][1]=a[i][1];
		        c[k][2]=a[i][2];
		        k++;
		        i++;
	        }
	        while(j<c2)//rest of second matrix
	        {
		        c[k][0]=b[j][0];
		        c[k][1]=b[j][1];
		        c[k][2]=b[j][2];
		        k++;
		        j++;
        	}
		c[0][2]=k-1;
	}
	for(int i=0;i<k;i++)
	{
		for(int j=0;j<3;j++)
		{
			printf("%d ",c[i][j]);
		}
		printf("\n");
	}
	return 0;
}
