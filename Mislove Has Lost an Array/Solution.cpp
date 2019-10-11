#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int i,mini=1,mine=0,maxi=1,maxo=0,n,s,e;
    cin>>n>>s>>e;
    
    for(i=1;i<=s-1;i++)
    {
        mini=2*mini;
        mine+=mini;
    }
mine+=n-s+1;
 
for(i=1;i<=e-1;i++)
{
    maxi=2*maxi;
    maxo+=maxi;
}
maxo+=1;

 
maxo+=(n-e)*(maxi);
cout<<mine<<" "<<maxo;
    return 0;
}
