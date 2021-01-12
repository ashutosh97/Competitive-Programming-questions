/*Given a string, a partitioning of the string is a palindrome partitioning if every substring of the partition is a palindrome. 
Example:
“aba|b|bbabb|a|b|aba” is a palindrome partitioning of “ababbbabbababa”.*/
#include<bits/stdc++.h>
#include<string.h>
#include<string>
using namespace std;
bool ispalindrome(string s, int i, int j) {	
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
    int min = INT_MAX;
    for(int k=i;k<j;k++)
    {
        int temp =1+ solve(s,i,k)+solve(s,k+1,j);
        if(min>temp)
        {
            min=temp;
        }

    }
    return min;

}
int main()
{   
    string s= "abcde";
    cout<<solve(s,0,s.length()-1)<<endl;;
    return 0;   
}