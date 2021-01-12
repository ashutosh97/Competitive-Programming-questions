/*Given two sequences, print the longest subsequence present in both of them.
Examples:
LCS for input Sequences “ABCDGH” and “AEDFHR” is “ADH” of length 3.
LCS for input Sequences “AGGTAB” and “GXTXAYB” is “GTAB” of length 4.*/
#include<bits/stdc++.h>
#include<string.h>
#include<string>
using namespace std;
int t[100][1000];

int LCS(string X,string Y, int m,int n)
{
    for (int i = 0; i < m+1; ++i)
    {
       for (int j = 0; j < n+1; ++j)
       {
          if(i==0||j==0)
            t[i][j]=0;
       }
    }

for (int i = 1; i < m+1; ++i)
{
    for(int j = 1; j < n+1; ++j)
    {
        if(X[i-1]==Y[j-1])
         { 
            t[i][j]=1+t[i-1][j-1];
         }
        else
        {
            t[i][j]=max(t[i-1][j],t[i][j-1]);
        }
    }
}
return t[m][n];
}
int main()
{
    string X="AGGTAB";
    string Y="GXTXAYB";
    int m=X.length();
    int n = Y.length();
    memset(t,-1,sizeof(t));
    LCS(X,Y,m,n);
    int i=m,j=n;
    string s;
    while (i>0 && j>0)
    {
        if(X[i-1]==Y[j-1])
        {
            s.push_back(X[i-1]);
            i--;j--;
        }
        else
        {
            if(t[i][j-1]>t[i-1][j])
            {
                j--;
            }
            else
            {
                i--;
            }
            
        }
        
    }
    reverse(s.begin(),s.end());
    cout<<s<<endl;
    cout<<t[m][n]<<endl;
    return 0;
}