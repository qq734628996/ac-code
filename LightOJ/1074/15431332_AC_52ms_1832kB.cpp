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
const int MAXN = 2e2+5, INF = 0x3f3f3f3f, MOD = 998244353;

int n, m, w[MAXN], d[MAXN], inq[MAXN], cnt[MAXN], kase;
vector<pii> E[MAXN];
inline int cube(int x) { return x*x*x; }

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    int T; scanf("%d", &T);
    for (kase = 1; kase <= T; kase++) {
        printf("Case %d:\n", kase);
        scanf("%d", &n);
        FOR(i,1,n) scanf("%d", &w[i]);
        scanf("%d", &m);
        FOR(i,1,n) E[i].clear();
        FOR(i,1,m) {
            int x, y; scanf("%d%d", &x, &y);
            E[x].pb(pii(y,cube(w[y]-w[x])));
        }
        memset(d+1, 0x3f, sizeof(int) * n);
        memset(cnt+1, 0, sizeof(int) * n);
        queue<int> Q;
        Q.push(1); d[1] = 0;
        while (!Q.empty()) {
            int u = Q.front(); Q.pop();
            inq[u] = 0;
            REP(i,SZ(E[u])) {
                int v = E[u][i].fi, dist = E[u][i].se;
                if (d[v] > d[u] + dist) {
                    d[v] = d[u] + dist;
                    if (inq[v] != kase) {
                        inq[v] = kase;
                        Q.push(v);
                        if (++cnt[v] > n) goto END;
                    }
                }
            }
        }
        END:
        int q; scanf("%d", &q);
        while (q--) {
            int x; scanf("%d", &x);
            if (d[x] < 3 || d[x] == INF) puts("?");
            else printf("%d\n", d[x]);
        }
    }

    return 0;
}


















































































