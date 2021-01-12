//recursive code maximum profit
#include<bits/stdc++.h>
using namespace std;
int max(int a, int b) { return (a > b) ? a : b; }
int knapsack(int weight[],int val[], int c,int n)
{  
    if(n==0||c==0)
    {
        return 0;
    }
    if(weight[n-1]<=c)
    {
       return max((val[n-1]+ knapsack(weight,val,c-weight[n-1],n-1)), knapsack(weight,val,c, n-1));
    }
    else if (weight[n-1]>c)
        return knapsack(weight,val,c,n-1);
   return 0;
}
int main()
{   int val[] = { 60, 100, 120 }; //example cases
    int wt[] = { 10, 20, 30 }; 
    int W = 50; 
    int n = sizeof(val) / sizeof(val[0]); 
    cout << knapsack( wt, val,W, n); 
    return 0;
}