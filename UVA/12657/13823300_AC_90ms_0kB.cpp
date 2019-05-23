#include <cstdio>

#define FOR(i,l,r) for(int i = l; i <= r; i++)
const int MAXN  = 1e5+5;
int n, m, R[MAXN], L[MAXN], op, X, Y, kase;
#define link(x,y) { R[x] = y; L[y] = x; }

int main()
{
    while (~scanf("%d%d", &n, &m)) {
        bool rev(false);
        R[0] = 1; L[n+1] = n;
        FOR(i,1,n) { R[i] = i+1; L[i] = i-1; }
        while (m--) {
            scanf("%d", &op);
            if (op == 4) { rev = !rev; continue; }
            scanf("%d%d", &X, &Y);
            int XL = L[X], XR = R[X], YL = L[Y], YR = R[Y];
            if (op == 3) {
                if (XR == Y) { link(XL, Y) link(Y, X) link(X, YR) }
                else if (YR == X) { link(YL, X) link(X, Y) link(Y, XR) }
                else { link(XL,Y) link(Y,XR) link(YL,X) link(X,YR) }
            } else if (XR != Y && ((op == 1 && !rev) || (op == 2 && rev)))
            { link(XL, XR) link(YL, X) link(X,Y) }
            else if (XL != Y && ((op == 2 && !rev) || (op == 1 && rev)))
            { link(XL, XR) link(Y,X) link(X,YR) }
        }
        long long res(0);
        if (!rev) for (int i = 1, k = R[0]; i <= n; res += k, i += 2, k = R[R[k]]);
        else for (int i = 1, k = L[n+1]; i <= n; res += k, i += 2, k = L[L[k]]);
        printf("Case %d: %lld\n", ++kase, res);
    }
    return 0;
}
