#include<bits/stdc++.h>
using namespace std;
int t[1001][1001];
int solve(int arr[],int i,int j)
{
    if(i>=j)
    {
        return 0;
    }
    if(t[i][j]!=-1)
    {
        return t[i][j];
    }
    int min = INT_MAX;
    for(int k=i;k<j;k++)
    {
        int temp = solve(arr,i,k)+solve(arr,k+1,j)+arr[i-1]*arr[k]*arr[j];
        if(min>temp)
        {
            min=temp;
        }

    }
    t[i][j]=min;
    return t[i][j];

}
int main()
{
    memset(t,-1,sizeof(t));
    int arr[]={40,30,20,30};
    cout<<solve(arr,1,(sizeof(arr)/sizeof(arr[0])-1));
    return 0;
}