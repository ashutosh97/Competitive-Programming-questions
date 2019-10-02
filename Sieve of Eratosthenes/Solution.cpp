#include <bits/stdc++.h>
using namespace std;

long long maxValue = 10000000;

vector<bool> sieve(long long n) {
    vector<bool> prime;
    prime.assign(n+1, true);

    prime[0] = prime[1] = false;

    for(int i=2; i<n+1; i++)
        if(prime[i])
            for(int j=i*2; j<n+1; j+=i)
                prime[j] = false;
    
    return prime;
}

int main() {
    int cases, n;
    vector<bool> prime = sieve(maxValue);

    scanf("%d", &cases);

    while(cases-- > 0) {
        scanf("%d", &n);
        
        for(int i=2; i<n+1; i++)
            if(prime[i])
                printf("%d ", i);

        printf("\n");
    }

    return 0;
}