#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i = 0; i < n; i++)
#define FOR(i,l,r) for(int i = l; i <= r; i++)
#define TR(e,x) for(auto e = x.begin(); e != x.end(); e++)
#define DEBUG(x) cout << #x << "=" << x << endl;
#define SHOW1(A,n) { REP(i,n-1) printf("%d ", A[i]); printf("%d\n", A[n-1]); }
#define SHOW2(A,m,n) { REP(i,m) { REP(j,n-1) printf("%d ", A[i][j]); printf("%d\n", A[i][n-1]); } }
#define PB push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) (int)((x).size())
typedef long long LL;
const int MAXN  = 1e3+5, INF = ~0U>>1, MOD = ~0U>>1;

int n, maxd, a[MAXN], vis[MAXN];

#define vld(x) (1<=(x) && (x)<=1000 && !vis[x])
bool dfs(int d, int ma)
{
    //printf("%d a: ", n); SHOW1(a, d+1)

    if (d > maxd) return false;

    if (ma * (1<<(maxd-d+1)) < n) return false;

    bool ok = false;
    for (int i = d; i >= d; i--) {
        for (int j = d; j >= 0; j--) {
            if (vld(a[i] + a[j])) {
                if (a[i] + a[j] == n) return true;
                a[d+1] = a[i] + a[j];
                vis[a[i]+a[j]] = 1;
                ok = dfs(d+1, max(ma, a[i] + a[j]));
                vis[a[i]+a[j]] = 0;
            }
            if (ok) return true;
        }
    }
    for (int i = d; i >= d; i--) {
        for (int j = d; j >= 0; j--) {
            if (vld(a[i] - a[j])) {
                if (a[i] - a[j] == n) return true;
                a[d+1] = a[i] - a[j];
                vis[a[i]-a[j]] = 1;
                ok = dfs(d+1, ma);
                vis[a[i]-a[j]] = 0;
            }
            if (ok) return true;
        }
    }
    return false;
}

int main()
{
#ifdef LOCAL
    //freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    while (scanf("%d", &n), n) {
        if (n == 1) { puts("0"); continue; }
        a[0] = 1; vis[1] = 1;
        for (maxd = 0; ; maxd++) {
                //DEBUG(maxd)
            if (dfs(0, 1)) { printf("%d\n", maxd+1); break; }
        }
    }

    return 0;
}















































































