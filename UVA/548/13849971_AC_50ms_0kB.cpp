#include <stdio.h>

const int MAXV = 1e4+5, INF = ~0U>>1;
int in[MAXV], po[MAXV], ans, id;

void solve(int* s1, int* s2, int len, int now)
{
    if (len == 1 && (*s1+now < ans || ( *s1+now == ans && *s1 < *(in+id) ))) { ans = *s1+now; id = s1-in; }
    now += *(s2 + len - 1);
    int i = -1;
    while (*(s1 + ++i) != *(s2 + len - 1));
    if (i) solve(s1, s2, i, now);
    if (i < len-1) solve(s1+i+1, s2+i, len-i-1, now);
}

int main()
{
    while (~scanf("%d", in)) {
        int n = 1;
        while (getchar() != '\n')
            scanf("%d", in + n++);
        for (int i = 0; i < n; i++)
            scanf("%d", po + i);
        ans = INF;
        solve(in, po, n, 0);
        printf("%d\n", *(in+id));
    }
}
