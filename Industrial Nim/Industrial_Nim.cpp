#include <bits/stdc++.h>
using namespace std;
 
vector<long long> vec;
bool nim()	/* return true if the first player will win */
{
		long long x=0;
		for(int i=0;i<vec.size();i++)		x=x^vec[i];
		return x>0;
}
 
long long f(long long n)		/* n&3 equivalent to n%4 */
{		
    	long long x=n&3;
 	    if(x==0)	return n;	if(x==1)	return 1;
		if(x==2)	return n+1;	if(x==3)	return 0;
}
 
  
 
int main() 
{ 
    long long n,x,m;
    cin>>n;
    while(n--)
    {
        cin>>x>>m;
        vec.push_back(f(x+m-1)^f(x-1));
    }
    if(nim())
        cout<<"tolik"<<endl;
    else
        cout<<"bolik"<<endl;
} 

