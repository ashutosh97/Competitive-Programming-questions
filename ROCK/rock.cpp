/*
***************************************************************************************************************
 
                          Author : SUBHENDU SETHI
                          Hackerrank Handle: subhendu_sethi
                          Codechef Handle: subhendu_sethi
                          SPOJ Handle: codekatte
                          Codeforces Handle: subhendu_sethi
                          UVA Handle: codekatte
 
**************************************************************************************************************
*/
#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define si(x) scanf("%d",&x)
#define sl(x) scanf("%lld",&x)
#define slu(x) scanf("%llu",&x)
#define sd(x) scanf("%lf",&x)
#define sc(x) scanf("%c",&x)
#define ss(x) scanf("%s",x)
#define vl vector<ll>
#define vi vector<int>
#define pb push_back
#define MOD 1000000007
#define MAXN 105050
#define SQRT 330
#define ls (node<<1)
#define rs ((node<<1)+1)
#define ii pair<int,int>
#define F first
#define S second
#define f(i,a,b) for(int i=a;i<b;i++)
ll dp[250][250];
char S[250];
ll n,t;
ll num0[250];
ll num1[250];
inline void refresh()
{
	memset(dp,-1,sizeof(dp));
	memset(num0,0,sizeof(num0));
	memset(num1,0,sizeof(num1));
}
inline void read()
{ 
	sl(t);
} 
ll rec(int a, int b)
{
	if(dp[a][b] != -1){
		return dp[a][b];
	}
	else if(a>b){
		return dp[a][b] = 0;
	}
	else if(a == b)
	{
		if(S[a] == '0')
			return dp[a][b] = 0;
		return dp[a][b] = 1;
	}
	else
	{
		ll tot0 = num0[b];
		ll tot1 = num1[b];
		if(a!=0){
			tot0-=num0[a-1];
			tot1-=num1[a-1];
		}
		if(tot1>tot0)
			return dp[a][b] = (b-a+1);
		else
		{
			ll ret = 0;
			for(int i=a;i<b;i++)
			{
				ret = max(ret,rec(a,i)+rec(i+1,b));
			}
			return dp[a][b] = ret;
		}
	}
}
inline void solve()
{ 
	while(t--)
	{
		refresh();
		sl(n);
		scanf("%s",S);
		f(i,0,n)
		{
			if(S[i] == '0')
				num0[i]=1;
			else
				num1[i]=1;
		}
		f(i,1,n)
		{
			num0[i]+=num0[i-1];
			num1[i]+=num1[i-1];
		}
		ll ans = rec(0,n-1);
		printf("%lld\n",ans);
	}
}  
int main() 
{
    read();
    solve();
    return 0;
}   