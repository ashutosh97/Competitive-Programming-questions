//Find the minimum possible difference of the sum of two chose subsets of a given array.
#include<bits/stdc++.h>
using namespace std;
bool t[100][1000];
bool subsetsum(int arr[], int sum,int n) //use of the subset-sum problem function
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
{   int arr[] = {1,2,7,8,9 }; //example cases
    int range=0;
    int n = sizeof(arr) / sizeof(arr[0]); 
    memset(t,false,sizeof(t));
    for(int i=0;i<n;i++)
    {
        range+=arr[i];
    }
   subsetsum(arr,range,n);
   int mn =INT_MAX;
   vector<int> v;
   for(int i=0;i<=range/2;i++)
   {
       if(t[n][i])
       {
           v.push_back(i);
       }
   }
   for(int i=0;i<v.size();i++)
   {
       mn = min(mn, range - 2* v[i]);
   }
  cout<<mn<<endl;// subsets are: {7.8} and {1,2,9} hence the difference will be 3.
    return 0;
}