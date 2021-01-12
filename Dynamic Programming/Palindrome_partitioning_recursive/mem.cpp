#include<bits/stdc++.h>
#include<string.h>
#include<string>
using namespace std;
int t[1001][1001];
bool ispalindrome(string s, int i, int j) 
{	
		if(i == j) {
			return true;
		}
		
		if(i > j) {
			return true;
		}
		
		while( i < j) {
			if(s[i] != s[j]) {
				return false;
			}
			
			i++;
			j--;
		}
		return true;
		
	}
int solve(string s,int i,int j)
{
    if(i>=j)
    {
        return 0;
    }
    if(ispalindrome(s,i,j))
    {
        return 0;
    }
    if(t[i][j]!=-1)
    {
        return t[i][j];
    }
    int min = INT_MAX; int left,right;
    for(int k=i;k<j;k++)
    {
       if(t[i][k]!=-1)
       {
           left=t[i][k];
       }
       else
       {
           left=solve(s,i,k);
       }
        if(t[k+1][j]!=-1)
       {
           right=t[k+1][j];
       }
       else
       {
           right=solve(s,k+1,j);
       }
       int temp=1+left+right;
        if(min>temp)
        {
            min=temp;
        }

    }
    return t[i][j]=min;

}
int main()
{   
    string s= "abcde";
    memset(t,-1,sizeof(t));
    cout<<solve(s,0,s.length()-1)<<endl;;
    return 0;   
}