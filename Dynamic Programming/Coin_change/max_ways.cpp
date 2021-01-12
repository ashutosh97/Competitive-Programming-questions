//Program to count how many ways exist that an amount can be broken into a number of denominations.
#include<bits/stdc++.h>
using namespace std;
int t[100][1000];
int counting(int arr[], int sum,int n) //unbounded subset sum
{  
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<sum+1;j++)
        {
            if(j==0)
             t[i][j]=1;
            
            if(i==0)
             t[i][j]=0;           
            
        }
    }
    t[0][0]=1;
 for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<sum+1;j++)
        {
            if(arr[i-1]<=j)
                {
                    t[i][j]= (t[i][j-arr[i-1]])+ t[i-1][j];
                }
            else if (arr[i-1]>j)
                t[i][j]=t[i-1][j];

        }
    }    
return t[n][sum];
}
int main()
{   int coin[] = {1,2,3}; //example cases
    int amount= 10; 
    int n = sizeof(coin) / sizeof(coin[0]); 
    memset(t,0,sizeof(t));
    int count= counting(coin,amount,n);
    cout<<count<<endl;
    return 0;
}