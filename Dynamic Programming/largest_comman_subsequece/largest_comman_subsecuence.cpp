#include <iostream>
#include<bits/stdc++.h>
#include <string>
using namespace std;
int solver(string s1,string s2,vector<vector<int>>&dp,int n,int m)
{
    if(s1.empty()||s2.empty())
        return 0;
    if(dp[n][m] >= 0)
        return dp[n][m];
    if(s1[0]==s2[0])
    {
        int ans = 1 + solver(s1.substr(1),s2.substr(1),dp,n-1,m-1);
            dp[n][m] = ans;
        return ans;
    }
        int ans1 = solver(s1,s2.substr(1),dp,n,m-1);
        int ans2 = solver(s1.substr(1),s2,dp,n-1,m);
        dp[n][m] = max(ans1,ans2);
        return max(ans1,ans2);
}
int lcs(string s1, string s2)
{
    int n = s1.length(),m=s2.length();
    vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
      int ans = solver( s1, s2, dp , s1.length(),s2.length());
      return ans;
}

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    cout << lcs(s1, s2);
}
