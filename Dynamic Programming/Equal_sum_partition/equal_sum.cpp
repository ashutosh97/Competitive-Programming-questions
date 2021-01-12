//Program to check whether 2 partitions exist which have equal sum.
#include<bits/stdc++.h>
using namespace std;
bool t[100][1000];        //t[n+1][sum+1]
bool equalsum(int arr[], int n)
{  int sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
    }
    if(sum%2!=0)
        return false;

  sum=sum/2;

  //same code as subset sum
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<sum+1;j++)
        {
            if(j==0)
             t[i][j]=true;
            
            if(i==0)
             t[i][j]=false;           
            
        }
    }
    t[0][0]=true;
 for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<sum+1;j++)
        {
            if(arr[i-1]<=j)
                {
                    t[i][j]= (t[i-1][j-arr[i-1]])|| t[i-1][j];
                }
            else if (arr[i-1]>j)
                t[i][j]=t[i-1][j];

        }
    }    
return t[n][sum];
}
int main()
{   int arr[] = { 2,4 }; //example cases
    int n = sizeof(arr) / sizeof(arr[0]); 
    memset(t,-false,sizeof(t));
    if(equalsum( arr,n))
        printf("YES");
    else
    {
        printf("NO");
    }
     
    return 0;
}