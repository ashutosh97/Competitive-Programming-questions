#include<stdio.h> 
int main() {
int n,i,a[10];
scanf("%d",&n);
for(i=0;i<=n;i++)
{
scanf("%d",&a[i]);
}
if(a[0]>a[1]&&a[2]>a[1]&&a[2]>a[3]&&a[4]>a[3])
printf("%d",n-2);
else
printf("%d",n);
return 0;
}
