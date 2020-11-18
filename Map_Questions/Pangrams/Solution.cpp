#include <bits/stdc++.h>
using namespace std;
int main()
{  
    int t,i,sum;
    cin>>t;
    while(t--){
    char ch;
    string s;
    int l,a[26];
    for(i=0;i<26;i++)
    cin>>a[i];
    cin>>s;
    l=s.length();
    map<char,int> m;
    for(ch='a';ch<='z';ch++)
    m[ch]++;
    for(i=0;i<l;i++)
    m[s[i]]++;
    map<char,int>::iterator j;
    i=0;
    sum=0;
    for(j=m.begin();j!=m.end();j++)
    {
        if(j->second==1)
        sum=sum+a[i];
        i++;
    }
    cout<<sum<<endl;}
    
}
