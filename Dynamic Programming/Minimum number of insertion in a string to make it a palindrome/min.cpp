/*Minimum number of insertions to make a string palindrome
Given a string, find the minimum number of characters to be inserted to form Palindrome string out of given string

Examples:
ab: Number of insertions required is 1. bab
aa: Number of insertions required is 0. aa*/
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
    string X="aebcbda";
    string Y=X;
    reverse(Y.begin(), Y.end()); 
    int m=X.length();
    int n = Y.length();
    memset(t,-1,sizeof(t));
    int d= m-LCS(X,Y,m,n);
    cout<<d<<endl;
    return 0;
}