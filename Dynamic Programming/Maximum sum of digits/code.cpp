#include <bits/stdc++.h>
#define MAX 100005
#define pb push_back
#define mp make_pair
#define M 1000000007
#define fi first
#define se second
#define inp(i, n, a) for(int i=0;i<n;i++) cin>>a[i];
#define int long long
using namespace std;

int sod(int n)
{
	int res = 0;
	while(n)
	{
		res = res + n%10;
		n /= 10;
	}
	return res;
}

signed main()
{
// ios_base::sync_with_stdio(false);
// cin.tie(NULL);

string n;
cin >> n;
string num1 = "", num2 = "";
for(int i=0; i<n.length(); i++)
{
	if(i==0)
	num1 += (n[i]-1);
	else
	num1 += "9";
}
int n1 = 0, ori = 0;
for(int i=0; i<num1.length(); i++)
{
	n1 = n1 * 10 + (num1[i]-'0');
	ori = ori * 10 + (n[i]-'0');
}
cout << sod(n1) + sod(ori-n1);
return 0;
}
