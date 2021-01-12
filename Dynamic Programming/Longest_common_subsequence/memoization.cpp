#include<bits/stdc++.h>
#include<string.h>
using namespace std;
int t[100][1000];
int LCS(string X,string Y, int m,int n)
{
    
   if(m==0||n==0)
    return 0;
    
             
   if(t[m][n]!=-1)
   {
   	return t[m][n];
    }

   if(X[m-1]==Y[n-1])
    {
     return t[m][n]= 1+LCS(X,Y,m-1,n-1);
    }
   else
   {
     return t[m][n]= max(LCS(X,Y,m,n-1),LCS(X,Y, m-1, n-1));
   }
            

}
int main()
{
    string X="sujffy";
    string Y="sujoyyyy";
    int m= X.length();
    int n = Y.length();
    memset(t,-1,sizeof(t));
    cout<<LCS(X,Y,m,n)<<endl;
    return 0;
}