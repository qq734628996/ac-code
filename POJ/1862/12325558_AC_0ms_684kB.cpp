#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<iostream>
#include<algorithm>

int main()
{
    int n, a[100];
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    std::sort(a, a+n);
    double ans = a[n-1];
    for (int i = n-2; i >= 0; i--) {
        ans = 2 * sqrt(ans * a[i]);
    }
    printf("%.3f", ans);
    return 0;
}