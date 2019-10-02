#include <bits/stdc++.h>
using namespace std;

const int MAX =  1005;
int sol[MAX];

int f(int x){
    return (x* (x + 1))/2;
}
void precompute(){
    for(int people  = 2; people < MAX; people++){
        int lim_level = max(2*people, 5);
        for (int level = 4; level < lim_level; level++)
            if(f(level) % people == 0){
                sol[people] = f(level);
                break;
            }
    }
}
int main(){
    precompute();
    int cases, n;
    scanf("%d", &cases);
    while(cases--){
        scanf("%d", &n);
        printf("%d\n", sol[n]);
    }
}

