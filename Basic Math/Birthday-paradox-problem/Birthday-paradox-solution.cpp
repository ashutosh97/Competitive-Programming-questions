#include <bits/stdc++.h>
using namespace std;
// C++ program to approximate number of people in Birthday Paradox
// problem
// Returns approximate number of people for a given probability
int find(double p)
{
    if (p != 1)
        return ceil(sqrt(2 * 365 * log(1 / (1 - p))));
    else return 366;
}
int main()
{
    
/*#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif*/
    cout << find(0.50);
}

