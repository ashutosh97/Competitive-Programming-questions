#include<bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef vector<LL> VLL;
typedef std::complex<double> CD;

#define PB              push_back
#define F               first
#define s               second
#define SZ(x)           x.size()
#define ALL(a)          std::begin(a), std::end(a)
#define IN_REP          int _t; cin >> _t ; while(_t--)
#define IOS             ios::sync_with_stdio(false);cin.tie(NULL)
#define FOR(i, a, b)    for(int i=(a);i<(b);i++)
#define REP(i, n)       FOR(i,0,n)
const double PI     =   acos(-1);
typedef std::valarray<CD> CArray;

// Cooley–Tukey FFT (in-place)
void fft(CArray &x) {
    // const size_t N = x.size();
    int N = SZ(x);
    if (N <= 1) return;

    // divide
    CArray even = x[std::slice(0, N / 2, 2)];
    CArray odd = x[std::slice(1, N / 2, 2)];

    // conquer
    fft(even);
    fft(odd);

    // combine
    // for (size_t k = 0; k < N/2; ++k){
    for (int k = 0; k < N / 2; ++k) {
        CD t = std::polar(1.0, -2 * PI * k / N) * odd[k];
        x[k] = even[k] + t;
        x[k + N / 2] = even[k] - t;
    }
}

// inverse fft (in-place)
void ifft(CArray &x) {
    // conjugate the complex numbers
    x = x.apply(std::conj);

    // forward fft
    fft(x);

    // conjugate the complex numbers again
    x = x.apply(std::conj);

    // scale the numbers
    x /= x.size();
}

int main() {
    IOS;
    IN_REP {
        int n;
        cin >> n;
        n++; // Given in question
        int size = 2 * (1 << int(ceil(log2(n))));

        CArray x(size), y(size);
        FOR(i, size - n, size) cin >> x[i];
        fft(x);
        FOR(i, size - n, size) cin >> y[i];
        fft(y);

        CArray res(size);
        res = x * y;
        ifft(res);
        VLL ans;
        REP(i, size - 1) {
            ans.PB(round(res[i].real()));
        }
        for (int i = size - 1 - (2 * n - 1); i < size - 1; i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
