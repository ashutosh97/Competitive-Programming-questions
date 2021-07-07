#include <bits/stdc++.h>
using namespace std;
#define ll long long int 
ll MAXN=10000001;
ll spf[10000001];
void sievespf()
{
    spf[1] = 1;
    for (int i=2; i<MAXN; i++)
        {spf[i] = i;}
    for (int i=4; i<MAXN; i+=2)
        spf[i] = 2;
    for (int i=3; i*i<MAXN; i++)
    {
        if (spf[i] == i)
        {
            for (int j=i*i; j<MAXN; j+=i)
                if (spf[j]==j)
                    spf[j] = i;
        }
    }
}

void getprimefactors(int x)
{
    
    while (x != 1)
    {
        cout<<spf[x]<<' ';
        int temp=spf[x];
        while(x%temp==0)
          x = x / temp;
    }
    cout<<'\n';
    return ;
}
int  main()
{
  fastio;
  sievespf();
  ll t;
  cin>>t;
  while(t--)
  {
      int n;
      cin>>n;
      getprimefactors(n);
  }
  return 0;
}