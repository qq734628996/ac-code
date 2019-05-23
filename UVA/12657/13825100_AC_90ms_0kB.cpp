#include <cstdio>

#define FOR(i,l,r) for(int i = l; i <= r; i++)
const int MAXN  = 1e5+5;
int n, m, R[MAXN], L[MAXN], op, X, Y, kase;
#define link(x,y) { R[x] = y; L[y] = x; }

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    freopen("o.txt", "w", stdout);
#endif //LOCAL

    while (~scanf("%d%d", &n, &m)) {
        bool rev(false);
        R[0] = 1; L[n+1] = n;
        FOR(i,1,n) { R[i] = i+1; L[i] = i-1; }
        while (m--) {
            scanf("%d", &op);
            if (op == 4) { rev = !rev; continue; }
            scanf("%d%d", &X, &Y);
            if (op == 3 && R[Y] == X) { int t = X; X = Y; Y = t; }
            if (op != 3 && rev) op = 3 - op;
            if (op == 1 && X == L[Y]) continue;
            if (op == 2 && X == R[Y]) continue;

            int XL = L[X], XR = R[X], YL = L[Y], YR = R[Y];
            if (op == 1) { link(XL, XR) link(YL, X) link(X, Y) }
            else if (op == 2) { link(XL, XR) link(Y, X) link(X, YR) }
            else if (XR == Y) { link(XL, Y) link(Y, X) link(X, YR) }
            else { link(XL, Y) link(Y, XR) link(YL, X) link(X, YR) }
        }
        long long res(0);
        if (!rev) for (int i = 1, k = R[0]; i <= n; res += k, i += 2, k = R[R[k]]);
        else for (int i = 1, k = L[n+1]; i <= n; res += k, i += 2, k = L[L[k]]);
        printf("Case %d: %lld\n", ++kase, res);
    }
    return 0;
}
