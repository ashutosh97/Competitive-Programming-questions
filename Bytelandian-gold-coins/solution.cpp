#include<bits/stdc++.h>
using namespace std;
map<int,long long> dp;
long long optcoins(int n){
    if(n<12)
        return n;
    if(dp.count(n))
        return dp[n];
    dp[n]=optcoins(n/2)+optcoins(n/3)+optcoins(n/4);
    return dp[n];
}
int main(){
    int x;
    while(scanf("%d",&x)!=EOF)
        printf("%lld\n",optcoins(x));
    return 0;
}
