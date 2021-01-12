//memoization code
#include<bits/stdc++.h>
using namespace std;
int t[100][1000];
int max(int a, int b) { return (a > b) ? a : b; }
int knapsack(int weight[],int val[], int c,int n)
{  
    if(n==0||c==0)
    {
        return 0;
    }
    if(t[n][c]!=-1)
    {
        return t[n][c];
    }


    if(weight[n-1]<=c)
    {
       return t[n][c]= max((val[n-1]+ knapsack(weight,val,c-weight[n-1],n-1)), knapsack(weight,val,c, n-1));
    }
    else if (weight[n-1]>c)
        return t[n][c]=knapsack(weight,val,c,n-1);
   return 0;
}
int main()
{   int val[] = { 60, 100, 120 }; //example cases
    int wt[] = { 10, 20, 30 }; 
    int W = 50; 
    memset(t,-1,sizeof(t));
    int n = sizeof(val) / sizeof(val[0]); 
    cout << knapsack( wt, val,W, n); 
    return 0;
}