#include <bits/stdc++.h>

using namespace std;


int main() 
{
	
long long n,a,b,num,den;

	int t;

	cin>>t;

	while(t--)

	{
	
	cin>>a;

	n=(-1+sqrt(1+(8*a)))/2;

	b=(n*(n+1))/2;

	if(a==b)

	{

	    if(a%2==0)

	    {

	        den=n;

	        num=1;

	        cout<<"TERM "<<a<<" IS "<<num<<"/"<<den<<endl;

	    }

	    else

	    {

	        den=1;

	        num=n;

	        cout<<"TERM "<<a<<" IS "<<num<<"/"<<den<<endl;

	    }
	}

	else

	{
 
   	if(n%2==0)

    	{

    	  den=a-b;

    	  num=n+2-den;

    	  cout<<"TERM "<<a<<" IS "<<num<<"/"<<den<<endl;

    	}

    	else

    	{

    	    num=a-b;

    	    den=n+2-num;

    	    cout<<"TERM "<<a<<" IS "<<num<<"/"<<den<<endl;

    	}
	}
	}
	return 0;
}