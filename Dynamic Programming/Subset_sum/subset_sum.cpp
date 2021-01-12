//Program to check whether a subset exists which adds up to the given sum.
#include<bits/stdc++.h>
using namespace std;
bool t[100][1000];
bool subsetsum(int arr[], int sum,int n)
{  
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
{   int arr[] = { 2,3,6,10 }; //example cases
    int sum= 18436; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    memset(t,false,sizeof(t));
    if(subsetsum( arr,sum,n))
        printf("YES");
    else
    {
        printf("NO");
    }
     
    return 0;
}