#include<stdio.h>
int c,fac;
int fact(int n)
{
	if(n==0){
		return 1;
	}
	fac=n*fact(n-1);
	return fac;
}
int main()
{
	 printf("enter a number ");
	 scanf("%d",&c);
	 fact(c);
	 printf("factorial of entered no. is %d",fac);
return 0;
}
