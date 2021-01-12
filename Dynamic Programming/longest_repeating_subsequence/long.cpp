/*Given a string, print the longest repeating subsequence such that the two subsequence don’t have same string character at same position, i.e., any i’th character in the two subsequences shouldn’t have the same index in the original string.
Example:
Input: str = "aab"
Output: "a"
The two subsequence are 'a'(first) and 'a' 
(second). Note that 'b' cannot be considered 
as part of subsequence as it would be at same
index in both.*/
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
        if(X[i-1]==Y[j-1]&& i!=j)
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
    string X="aabbdefgcc";
    string Y=X;
    int m=X.length();
    int n = Y.length();
    memset(t,-1,sizeof(t));
    cout<<LCS(X,Y,m,n)<<endl;
    return 0;
}