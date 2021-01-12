/*Longest Common Substring(Dynamic Programming)
Given two strings ‘X’ and ‘Y’, find the length of the longest common substring.
Examples:

Input : X = “GeeksforGeeks”, y = “GeeksQuiz”
Output : 5
The longest common substring is “Geeks” and is of length 5.*/
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
            t[i][j]=0;
        }
    }
}
auto max= t[0][0];

for (int i = 0; i < m+1; ++i)
{
  for (int j = 0; j < n+1; ++j)
  {
    if(max<t[i][j])
      max=t[i][j];
  }
}
return max;


}
int main()
{
    string X="GeeksforGeeks";
    string Y="GeeksQuiz";
    int m = X.length();
    int n = Y.length();
    memset(t,-1,sizeof(t));
    cout<<LCS(X,Y,m,n)<<endl;
    return 0;
}