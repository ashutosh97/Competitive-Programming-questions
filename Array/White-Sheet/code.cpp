//https://codeforces.com/contest/1216/problem/C
//587-Div 3-C
#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	ll x11,x12,y11,y12;
	ll x21,x22,y21,y22;
	ll x31,x32,y31,y32;

	ll area = 0;

	cin>>x11>>y11>>x12>>y12;
	cin>>x21>>y21>>x22>>y22;
	cin>>x31>>y31>>x32>>y32;

	area = abs(x11-x12)*abs(y11-y12);
	x21 = max(x11,x21);
	y21 = max(y11,y21);
	x22 = min(x12,x22);
	y22 = min(y12,y22);
	x31 = max(x11,x31);
	y31 = max(y11,y31);
	x32 = min(x12,x32);
	y32 = min(y12,y32);
	ll a1,a2,b1,b2;
	if(x21 < x22 && y21 < y22) area -= abs(x21-x22)*abs(y21-y22);
	if(x31 < x32 && y31 < y32) area -= abs(x31-x32)*abs(y31-y32);
	if((x21<x31 && x22>x31) || (x21<x32 && x22>x32))
	{
		if((y21 < y31 && y22 > y31) || (y21 < y32 && y22 > y32))
		{
			ll narea = 0;

		}
	}

	a1 = max(x21,x31);
	b1 = max(y21,y31);
	a2 = min(x22,x32);
	b2 = min(y22,y32);

	if(a1 < a2 && b1 < b2)	area += abs(a2-a1)*abs(b2-b1);

	if(area > 0)	cout<<"YES\n";
	else			cout<<"NO\n";

	return 0;
}