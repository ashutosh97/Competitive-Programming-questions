#include<stdio.h>
#include<string.h>
int main() 
{
	long long int T,m;
	scanf("%lld",&T);
	for(m=0;m<T;m++)

	{	char s1[100001],s2[100001],a;
		long long int i=1,k,b,j=0,c,l,u,N,z=999999,arr[100001],brr[100001];
		scanf("%s%s%lld",s1,s2,&N);
		k = strlen(s1);
		a = s2[0];
		for(i=0;i<k;i++)
		{if(s1[i]==a)
			{
				arr[j]=i;
				j++;
			}
		}
		i=0;
		j--;
		while(j-(N-1)>=0)
		{ 
			brr[i] = arr[j]-arr[j-(N-1)]+1;
			i++;
			j--;
		}	

		for(l=0;l<i;l++)
		{
			if(brr[l]<z)	
			z = brr[l];
		}
		printf("%lld\n",z);
	} 
	return 0;
}


