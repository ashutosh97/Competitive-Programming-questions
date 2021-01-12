/*Minimum number of deletions to make a string palindrome
Given a string of size ‘n’. The task is to remove or delete minimum number of characters from the string so that the resultant string is palindrome.
Example :
Input : aebcbda
Output : 2
Remove characters 'e' and 'd'
Resultant string will be 'abcba'
which is a palindromic string*/
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