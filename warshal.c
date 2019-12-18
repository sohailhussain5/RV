#include<stdio.h>
int a[10][10],p[10][10],n;

void path()
{
	int i,j,k;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			p[i][j]=a[i][j];
		}
	}
	for(k=0;k<n;k++)
	{
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if(p[i][j]==0 && p[i][k]==1 && p[k][j]==1)
					p[i][j]=1;
			}
		}
	}
}


void main()
{
	int i,j,k=0;
	printf("Enter the number vertices\n");
	scanf("%d",&n);
	printf("Enter the adjacency matrix\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	path();
	printf("The path  matrix is\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d\t",p[i][j]);

		}
		printf("\n");
	}
}

