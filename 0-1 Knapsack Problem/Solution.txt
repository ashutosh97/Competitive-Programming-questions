#include<stdio.h>
#include<stdlib.h>

int max(int a, int b)
{
	if (a>b)
		return a;
	else
		return b;
}

int main()
{
	int n, value[100], capacity, weight[100],i,j,K[100][100];
	printf("Input number of  items:");
	scanf("%d",&n);
	printf("Enter values:");
	for(i=0;i<n;i++)
		scanf("%d",&value[i]);
	printf("Enter weights:");
	for(i=0;i<n;i++)
		scanf("%d",&weight[i]);	
	printf("Enter Capacity:");
	scanf("%d",&capacity);
	for(i=0;i<=n;i++)
		for(j=0;j<=capacity;j++)
		{
			if(i==0 || j==0)
				K[i][j]=0;
			else if (weight[i-1]<=j)
				K[i][j]=max(K[i-1][j],K[i-1][j-weight[i-1]]+value[i-1]);
			else
				K[i][j]=K[i-1][j];
		}	
	printf("%d",K[n][capacity]);
	return 0;
}
