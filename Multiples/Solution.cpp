#include<iostream>
using namespace std;

int main()
{
	#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output1.txt","w",stdout);
    #endif

    int n,q;
    cin>>n;
    cin>>q;
    int cnt=0;

    for(int i=1;i<n;i++)
    {
    	if(i%2==0)
    	{
    		cnt++;
    	}
    }

    cout<<cnt;
}