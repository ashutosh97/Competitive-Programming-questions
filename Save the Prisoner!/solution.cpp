#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,n,m,s;
    cin>>t;
    while(t>0)
    {
        cin>>n>>m>>s;
        s=s+m%n -1;
        if(m%n==0)
        s=s+n;
        if(s>n)
        s=s%n;
        cout<<s<<endl;
        t--;
    }
    return 0;
}

