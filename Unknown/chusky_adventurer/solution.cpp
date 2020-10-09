#include <bits/stdc++.h>
using namespace std;
typedef long long int i64;

const i64 MOD = 1000000007;
const int limit = 1000001;

int cat[limit];

i64 num(i64 x){
    return (((2ll*x)%MOD + 2ll)*((2ll*x)%MOD + 1ll))%MOD;
}

i64 den(i64 x){
    return ((x + 2ll)*(x + 1ll))%MOD;
}

i64 fast_pow(i64 x, i64 pow){
    if (pow == 0) return 1;
    if (pow == 1) return x;
    if (pow % 2ll == 0ll){
        i64 prod = fast_pow(x, pow / 2ll);
        return (prod * prod) % MOD;
    } 
    else{
        i64 prod = fast_pow(x, pow / 2ll);
        return (((prod * prod) % MOD) * x) % MOD;
    }
}

i64 inverse(i64 x){
    //because MOD is prime, we can use Fermat's little theorem
    return fast_pow(x, MOD - 2);
}

void precompute(){
    cat[0] = 1;
    for(int i = 1; i < limit; i++){
        i64 ans = (1ll*cat[i-1] * num(i)) % MOD;
        ans = (ans * inverse(den(i))) % MOD;
        cat[i] = (int)(ans);
    }
}
int main(){
    precompute();
    int test;
    scanf("%d", &test);
    while(test--){
        int x;
        scanf("%d", &x);
        printf("%d\n", cat[x - 1]);
    }
}

