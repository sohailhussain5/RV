#include<stdio.h>
 
int max(int a, int b) { return (a > b)? a : b; }
 
int knapSack(int W, int wt[], int val[], int n)
{
   int i, j, x[n];
   int K[n+1][W+1];
 
   for (i = 0; i <= n; i++)
   {
       for (j = 0; j <= W; j++)
       {
           if (i==0 || j==0)
               K[i][j] = 0;
           else if (wt[i-1] <= j)
                 K[i][j] = max(val[i-1] + K[i-1][j-wt[i-1]],  K[i-1][j]);
           else
                 K[i][j] = K[i-1][j];
       }
   
	}
 
	printf("\n");
	i = n;
	j = W;
	while(i != 0 && j != 0)
	{
		if(K[i][j] != K[i-1][j])
		{
			x[i] = 1;
			j = j - wt[i-1];
		}
		i--;
	}

	printf("\nSelected Objects:\n");
	for(i=1; i<=n; i++)
		printf("%d\t",i);
	printf("\n");
	for(i=1; i<=n; i++)
	{
		if(x[i] == 1)
			printf("1\t");
		else
			printf("0\t");
	}
	printf("\n");
 
	return K[n][W];
}
 
int main()
{
    int i, n, val[20], wt[20], W;
    
    printf("Enter number of items:");
    scanf("%d", &n);
    
    printf("Enter value and weight of items:\n");
    for(i = 0;i < n; ++i){
    	scanf("%d %d", &val[i], &wt[i]);
    }
 
    printf("Enter size of knapsack:");
    scanf("%d", &W);
    
    printf(" The total Profit => %d\n", knapSack(W, wt, val, n));
    return 0;
}
