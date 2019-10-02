#include <bits/stdc++.h>
using namespace std;

int memo[11][100][100] = {0};

int solve(int k, int start, int end){
    if(k == 0){
        return INT_MAX;
    }
    if(k == 1){
        return (end * (end + 1) / 2 - (start * (start + 1) / 2));
    }
    if(start == end){
        return 0;
    }

    if(memo[k][start][end] == 0){
        int result = INT_MAX;
        for(int i = start + 1; i <= end; i++){
            result = min(result, i + max(solve(k-1, start, i-1), solve(k, i, end)));
        }
        memo[k][start][end] = result;
    }
    return memo[k][start][end];
}

int main(){
    int nCases;
    cin >> nCases;
    while(nCases--){
        int mailboxes, firecrackers;
        cin >> mailboxes >> firecrackers;
        cout << solve(mailboxes, 0, firecrackers) << endl;
    }
    return 0;   
}
