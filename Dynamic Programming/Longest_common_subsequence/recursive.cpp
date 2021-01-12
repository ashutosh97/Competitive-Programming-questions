#include<bits/stdc++.h>
#include<string.h>
#include<string>
using namespace std;
int LCS(string X,string Y, int m,int n)
{
    if(m==0||n==0)
        return 0;
    

if(X[m-1]==Y[n-1])
{
    return 1+LCS(X,Y,m-1,n-1);
}
else
{
    return max(LCS (X,Y,m,n-1),LCS(X,Y, m-1, n-1));
}

}
int main()
{
    string X="sujoy";
    string Y="sujoyy";
    int m=X.length();
    int n = Y.length();
    cout<<LCS(X,Y,m,n)<<endl;
    return 0;
}