//Program to fin dthe minimum number of coins required to add up to a given denomination.
#include<bits/stdc++.h>
using namespace std;
int t[100][1000];
int counting(int arr[], int sum,int n) //unbounded subset sum
{  
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<sum+1;j++)
        {
            if(i==0)
             t[i][j]=INT_MAX-1;   
            if(j==0)
             t[i][j]=0;
                            
        }
    }
    int j=1;
 for(int i =1;j<sum+1;j++) //twist in the initialization
 {
     if(j%arr[0]==0)
     {
         t[i][j]=j/arr[0];
     }
     else
     {
         t[i][j]=INT_MAX-1;
     }
     
 }

 for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<sum+1;j++)
        {
            if(arr[i-1]<=j)
                {
                    t[i][j]= min(1+t[i][j-arr[i-1]],t[i-1][j]);
                }
            else if (arr[i-1]>j)
                t[i][j]=t[i-1][j];

        }
    }    
return t[n][sum];
}
int main()
{   int coin[] = {9, 6, 5, 1}; //example cases
    int amount= 11; 
    int n = sizeof(coin) / sizeof(coin[0]); 
    memset(t,0,sizeof(t));
    int count= counting(coin,amount,n);
    cout<<count<<endl;
    return 0;
}