#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int bag;
    cin>>bag;
    int weight[n + 2];
    int value[n + 2];
    for(int i = 0; i < n; i++){
        cin>>weight[i];
    }
    for(int i = 0; i < n; i++){
        cin>>value[i];
    }
    int dp[n + 2][bag + 2];
    memset(dp, 0, sizeof dp);
    dp[0][0] = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= bag; j++){
            if(j >= weight[i-1]) dp[i][j] = max(dp[i - 1][j - weight[i-1]] + value[i-1], dp[i-1][j]);
            dp[i][j] = max(dp[i-1][j], dp[i][j]);
            // cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
        }
    }
    int ans = -1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j <=bag; j++){
            ans = max(dp[i][j], ans);
        }
    }
    cout<<ans<<endl;
    return 0;  
}   