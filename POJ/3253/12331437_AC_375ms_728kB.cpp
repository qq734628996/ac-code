#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<iostream>
#include<algorithm>
int n, a[20005];
long long ans;

void f(int index)
{
    if (index < n-1) {
        int bak = (a[index+1] += a[index]), i;
        for (i = index+1; i+1 < n && a[i+1] < bak; i++) {
            a[i] = a[i+1];
        }
        ans += a[i] = bak;
        f(index+1);
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    if (n == 1) {
        printf("%d\n", a[0]);
        return 0;
    }
    std::sort(a, a+n);
    f(0);
    printf("%lld\n", ans);
    return 0;
}
