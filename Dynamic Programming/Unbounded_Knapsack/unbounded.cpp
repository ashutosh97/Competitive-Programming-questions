//dp code maximum profit
#include<bits/stdc++.h>
using namespace std;
int t[100][1000];
int max(int a, int b) { return (a > b) ? a : b; }
int knapsack(int weight[],int val[], int c,int n)
{  
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<c+1;j++)
        {
            if(i==0||j==0)
            t[i][j]=0;
        }
    }
 for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<c+1;j++)
        {
            if(weight[i-1]<=j)
                {
                    t[i][j]= max((val[i-1]+ t[i-1][j-weight[i-1]]), t[i-1][j]);
                }
            else if (weight[i-1]>j)
                t[i][j]=t[i-1][j];

        }
    }    
return t[n][c];
}
int main()
{   int val[] = { 60, 100, 120 }; //example cases
    int wt[] = { 10, 20, 30 }; 
    int W = 50; 
    int n = sizeof(val) / sizeof(val[0]); 
    memset(t,-1,sizeof(t));
    cout << knapsack( wt, val,W, n); 
    return 0;
}