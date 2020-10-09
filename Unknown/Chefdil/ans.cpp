#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string a;
        cin>>a;
        int b=0;
        for(int i=0;i<a.size();i++)
            b+=a[i]-'0';
        //cout<<b;
        if(b%2)
            cout<<"WIN"<<endl;
        else
            cout<<"LOSE"<<endl;
    }
}
