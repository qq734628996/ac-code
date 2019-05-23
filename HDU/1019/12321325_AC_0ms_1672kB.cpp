#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<algorithm>

int gcd(int m, int n)
{
    return n == 0 ? m : gcd(n, m%n);
}

int f(int m, int n)
{
    if (m < n) {
        std::swap(m, n);
    }
    int t = gcd(m, n);
    return (m/t) * (n/t) * t;
}

int main()
{
    int T, n, num;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        int ans = 1;
        while (n--) {
            scanf("%d", &num);
            ans = f(ans, num);
        }
        printf("%d\n", ans);
    }
}