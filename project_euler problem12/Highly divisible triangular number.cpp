#include <bits/stdc++.h>
using namespace std;

long long int fun(long long int num)
{
    long long int n = num;
    long long int i = 2;
    long long int p = 1;
    if (num == 1)
        return 1;
    while (i*i <= n)
    {
        long long int c = 1;
        while (n % i == 0)
        {
            n = n/i;
            c ++;
        }
        i++;
        p = p*c;
    } 
    if (n == num || n > 1)
        p = p*2;
    return p;
}

int main()
{
    long long int x;
    for (long long int i = 1; i < 13500; i ++)
    {
        x = i*(i+1)/2;
        if (x == 76576500)
            printf ("%lld\n", fun(x));
        if (fun(x) >= 500)
        {
            printf ("%lld\n", x);
            break;
        }
    }
    return 0;
}