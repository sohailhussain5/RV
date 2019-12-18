#include<stdio.h>
int p[10][10],n;
int min(int,int);
int path()
{
	int i,j,k;
	for(k=0;k<n;k++)
	{
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if(i==j)
					p[i][j]=0;
				else
					p[i][j] = min(p[i][j],p[i][k]+p[k][j]);
			}
		}
	}

}

int min(int a,int b)
{
	if(a<b)
		return a;
	else 
		return b;
}

void main()
{
	int i,j;
	printf("Enter number of vertices\n");
	scanf("%d",&n);
	printf("Enter adjacancy matrix\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&p[i][j]);
			if(p[i][j]==0 && i!=j)
				p[i][j]=99;
		}
	}

	path();
	printf("The path matrix is\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d\t",p[i][j]);
		}
		printf("\n");


}
}

