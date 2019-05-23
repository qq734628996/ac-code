#include <cstdio>
int main()
{
    int T, m, n;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &m, &n);
        int ans = 1;
        while (--m)
            if (n & 1) { ans <<= 1; n = (n+1)>>1; }
            else { ans = ans*2 + 1; n >>= 1; }
        printf("%d\n", ans);
    }
    return 0;
}