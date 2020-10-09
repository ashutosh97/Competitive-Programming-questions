#include <stdio.h>
#include <algorithm>
 
using namespace std;
 
const int N = 5e4 + 10;
 
int n, k;
int par[N], lab[N];
 
int anc(int u) {
    if (u == par[u]) return u;
    int tmp = par[u];
    par[u] = anc(par[u]);
    lab[u] = lab[tmp] + lab[u];
    return par[u];
}
 
int main() {
 //   freopen("input.in", "r", stdin);
//    freopen("output.out", "w", stdout);
 
    int test; scanf("%d", &test);
    while (test--) {
        scanf("%d%d", &n, &k);
        for (int i = 1; i <= n; ++i) {
            par[i] = i;
            lab[i] = 0;
        }
        int answer = 0;
        while (k--) {
            int t, x, y; scanf("%d%d%d", &t, &x, &y);
            if (x > n || y > n) { answer++; continue; }
            int px = anc(x), py = anc(y);
            t--;
            if (px == py) {
                int tmp = (lab[x] - lab[y]) % 3; if (tmp < 0) tmp += 3;
                if (tmp != t) answer++;
            } else {
                par[px] = py;
                int i = (lab[x] - lab[y] - t) % 3;
                lab[px] = i < 0 ? -i : -i + 3;
            }
        }
        printf("%d\n", answer);
    }
 
    return 0;
}
  

