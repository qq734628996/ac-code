#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i = 0; i < n; i++)
#define PER(i,n) for(int i = n-1; i >= 0; i--)
#define FOR(i,l,r) for(int i = l; i <= r; i++)
#define ROF(i,l,r) for(int i = r; i >= l; i--)
#define TR(e,x) for(auto e = x.begin(); e != x.end(); e++)
#define DEBUG(x) cout << #x << "=" << x << endl;
#define SHOW1(A,n) { REP(i,n-1) printf("%d ", A[i]); printf("%d\n", A[n-1]); }
#define SHOW2(A,m,n) { REP(i,m) { REP(j,n-1) printf("%d ", A[i][j]); printf("%d\n", A[i][n-1]); } }
#define pb push_back
#define fi first
#define se second
#define ALL(x) x.begin(),x.end()
#define SZ(x) (int)((x).size())
typedef long long LL;
typedef pair<int, int> pii;
const int MAXN = 1e2+5, INF = 0x3f3f3f3f, MOD = 998244353;

int n, m, q, g[MAXN][MAXN], kase;

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    while (scanf("%d%d%d", &n, &m, &q), n) {
        if (kase++) puts("");
        printf("Case #%d\n", kase);
        FOR(i,1,n)FOR(j,1,n) g[i][j] = i==j ? 0 : INF;
        REP(i,m) {
            int x, y, z; scanf("%d%d%d", &x, &y, &z);
            g[x][y] = g[y][x] = min(g[x][y], z);
        }
        FOR(k,1,n)FOR(i,1,n)FOR(j,1,n) g[i][j] = min(g[i][j], max(g[i][k], g[k][j]));
        REP(i,q) {
            int x, y; scanf("%d%d", &x, &y);
            if (g[x][y] == INF) puts("no path");
            else printf("%d\n", g[x][y]);
        }
    }

    return 0;
}


















































































