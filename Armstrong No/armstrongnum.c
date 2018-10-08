#include<stdio.h>
#include<math.h>
 
 int main()
 {
 	int i, temp,num,count=0,sum=0;

    scanf("%d",&num);
	
 	temp=num;
 	while(temp!=0)
 	{ 
 	 count++;
 	 temp=temp/10;
	 }
	 temp=num;
	 while(temp!=0)
	 {
	 	sum=sum + pow(temp%10,count);
	 	temp=temp/10;
	 }
	 printf("%d",sum);
	 
	 //and if sum is equal to num then that no is said to be Armstrong number.TRy 371
	 return 0;
 }
