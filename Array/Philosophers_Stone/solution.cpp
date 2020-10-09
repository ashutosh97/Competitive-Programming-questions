#include<bits/stdc++.h>
using namespace std;
int main(void)
{
  int t;
  cin>>t;
  while(t--)
  {
    int r,c;
    cin>>r>>c;
    int arr[r][c+2]={0};
    arr[0][c+1]=0;

    for(int i=0;i<r;i++)
     for(int j=1;j<=c;j++)
       cin>>arr[i][j];

    for(int i=r-2;i>=0;i--)
     for(int j=1;j<=c;j++)
       arr[i][j]+=max((arr[i+1][j-1]),max(arr[i+1][j],arr[i+1][j+1]));

    int max = INT_MIN;
    for(int i=1;i<=c;i++)
     if(arr[0][i]>max)
       max = arr[0][i];

    cout<<max<<"\n";
  }
}
