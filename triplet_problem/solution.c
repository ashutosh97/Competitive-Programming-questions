#include<stdio.h>

void sort(int a[],int);
void findtriplet(int a[],int n)
{
 sort(a,n);
 for(int k=n-1;k>=0;k--)
 {
  int i=0,j=k-1;
  while(i<j)
  {
    if(a[k] == a[i]+a[j])
    {
      printf("%d %d %d\n",a[i],a[j],a[k]);
      return;
    }
    else if(a[k] > (a[i]+a[j]))
       i++;
    else 
       j--;
  }
 }
 printf("No such triplet exists\n");
}

void sort(int a[],int n)
{
 for(int i=0;i<n-1;i++)
 {
   for(int j=0;j<=n-1-i;j++)
   {
     if(a[j] > a[j+1])
     { 
      int t;
      t = a[j];
      a[j] = a[j+1];
      a[j+1] = t;
     }
   }
 }
}

int main()
{
 int a[9] = {5,32,1,7,10,50,15,21,2};
 findtriplet(a,9);
 return 0;
}
