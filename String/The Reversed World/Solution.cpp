#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
 
#include <cmath>
#include <cstdio>
#include <queue>
#include <list>
#include <stack>
#include <utility>
#include <numeric>
#include <map>
#include <cctype>
#include <cstring>
#include <sstream>
#include <cstdlib>
#include <cassert>
#include <iomanip>
#include <set>
 
using namespace std;
 
#define F(a,b) for(int a=0;a<b;a++)
#define REP(a,b) for(int a=0;a<b;a++)
#define FOR(a,b,c) for(int a=b;a<c;a++)
#define FORD(a,b,c) for(int a=b;a>=c;a--)
 
#define S scanf
#define P printf
 
#define LEN(x) ((int)x.length())
#define SZ(x) ((int)x.size())
#define ALL(x) x.begin(), x.end()
#define MP(x,y) make_pair(x,y)
#define PB(x) push_back(x)
#define INF 1000000000
 
typedef long long LL;
typedef pair<int,int> PII;
typedef pair<int, PII> PIII;
typedef vector<int> VI;
typedef vector<bool> VB;
typedef vector<string> VS;
 
//int d[][2]={{-1.0},{1,0},{0,-1},{0,1}};
 
char a[1000005];
char b[1000005];
char c[1000005];
char minN[1000005], maxN[1000005];
//char ans[1000005];
//char D[1000005];
int digC[10];
int fDC[10];
int tDC;
int n;
 
bool solveB(int st)
{
b[0] = 0;
int tmpst = st;
int i = n-1;
VB db(n);
bool fAns = false;
while( i < n )
{
if( !db[i] )
{
db[i] = true;
if( digC[ minN[i] - '0' ] )
{
a[i] = minN[i];
digC[ minN[i] - '0' ]--;
i--;
}
else
{
FORD( j, minN[i]-'0' - 1, 0 )
{
if( digC[j] )
{
a[i] = j + '0';
//keep Digit count
if( !fAns )
{
tDC = 0;
REP(xx,10) { fDC[xx] = digC[xx]; tDC+=digC[xx]; }
strcpy( b, a+i );
fDC[j]--;
tDC--;
}
else
{
int za = 0, zb = 0;
bool fl = false;
REP(xx,10)
{
za += fDC[xx];
zb += digC[xx] + ((j==xx)?-1:0);
if( za == tDC )
{
if( zb > za )
{
if( b[0]-'0' > xx ) fl =true;
}
break;
}
if( za < zb ) fl = true;
else if( za > zb ) break;
}
if( fl )
{
tDC = 0;
REP(xx,10) { fDC[xx] = digC[xx]; tDC+=digC[xx]; }
strcpy( b, a+i );
fDC[j]--;
tDC--;
}
}
fAns = true;
}
}
i++;
}
}
else
{
if( minN[i] == a[i] )
digC[ a[i]-'0' ]++;
 
FORD( j, minN[i]-'0' - 1, 0 )
{
if( digC[j] )
{
a[i] = j + '0';
 
//keep Digit count
if( !fAns )
{
tDC = 0;
REP(xx,10) { fDC[xx] = digC[xx]; tDC+=digC[xx]; }
strcpy( b, a+i );
fDC[j]--;
tDC--;
}
else
{
int za = 0, zb = 0;
bool fl = false;
REP(xx,10)
{
za += fDC[xx];
zb += digC[xx] + ((j==xx)?-1:0);
if( za == tDC )
{
if( zb > za )
{
if( b[0]-'0' > xx ) fl =true;
}
break;
}
if( za < zb ) fl = true;
else if( za > zb ) break;
}
if( fl )
{
tDC = 0;
REP(xx,10) { fDC[xx] = digC[xx]; tDC+=digC[xx]; }
strcpy( b, a+i );
fDC[j]--;
tDC--;
}
}
fAns = true;
}
}
i++;
}
}
if( fAns )
{
REP(xx,10)
{
while( fDC[xx] )
{
a[tmpst] = xx + '0';
tmpst++;
fDC[xx]--;
}
}
a[tmpst] = 0;
strcat(a,b );
puts(a);
return true;
}
return false;
}
 
bool solveF()
{
a[n] = 0;
int i = 0;
VB d(n);
while( i >= 0 )
{
if( !d[i] )
{
d[i] = true;
if( digC[ maxN[i]-'0' ] )
{
a[i] = maxN[i];
digC[ maxN[i]-'0' ]--;
i++;
}
else
{
FOR( j, maxN[i]-'0' + 1, 10 )
{
if( digC[j] )
{
a[i] = j + '0';
digC[j]--;
if( solveB(i+1) ) return true;
digC[j]++;
}
}
i--;
}
}
else
{
if( maxN[i] == a[i] )
digC[ a[i]-'0' ]++;
FOR( j, maxN[i]-'0' + 1, 10 )
{
if( digC[j] )
{
a[i] = j + '0';
digC[j]--;
if( solveB(i+1) ) return true;
digC[j]++;
}
}
i--;
}
}
return false;
}
 
int main()
{
int t; S("%d", &t );
while( t-- )
{
S("%d", &n);
gets(a);
gets(a);
gets(b);
gets(c);
//S("%s%s%s", a, b, c );
if( strcmp(a,b) > 0 )
strcpy( maxN, a );
else
strcpy( maxN, b );
reverse(a, a + n );
reverse(b, b + n );
if( strcmp(a,b) < 0 )
strcpy( minN, a );
else
strcpy( minN, b );
REP(i,10) digC[i] = 0;
REP(i,n ) digC[ c[i]-'0' ]++;
int ax = 0, ay = n-1;
REP(i,10)
{
REP(j,digC[i])
{
c[ax] = i+'0';
a[ay] = i + '0';
ax++; ay--;
}
}
c[n] = 0; a[n] = 0;
 
if( strcmp( a, maxN ) > 0 && strcmp( c, minN ) < 0 )
{
reverse( minN, minN + n );
if( !solveF() ) P("-1\n");
}
else puts("-1");
}
return 0;
}