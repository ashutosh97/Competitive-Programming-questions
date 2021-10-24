#include <bits/stdc++.h>
using namespace std;
void Generate_Parenthesis(int open, int close, vector<string> &ans, string s)
{
    if (close == 0)
    {
        ans.push_back(s);
        return;
    }
    if (open)
    {
        string temp = s;
        temp += '(';
        Generate_Parenthesis(open - 1, close, ans, temp);
    }
    if (close > open)
    {
        string temp = s;
        temp += ')';
        Generate_Parenthesis(open, close - 1, ans, temp);
    }
}
int main()
{
    int n;
    cin >> n;
    vector<string> ans;
    Generate_Parenthesis(n, n, ans, "");
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << endl;
}