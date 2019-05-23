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
const int MAXN = 105, INF = 0x3f3f3f3f, MOD = 1e9+7;

int n, m, u[MAXN*MAXN], v[MAXN*MAXN], w[MAXN*MAXN], r[MAXN*MAXN], p[MAXN];
bool cmp(const int i, const int j) { return w[i] < w[j]; }
int Find(int x) { return p[x] == x ? x : p[x] = Find(p[x]); }
bool jdg()
{
    FOR(i,2,n) if (Find(i) != Find(1)) return false;
    return true;
}

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    while (scanf("%d%d", &n, &m), n) {
        FOR(i,1,m) scanf("%d%d%d", &u[i], &v[i], &w[i]);
        FOR(i,1,m) r[i] = i;
        sort(r+1, r+1+m, cmp);
        int ans = INF;
        FOR(L,1,m) {
            FOR(i,1,n) p[i] = i;
            int R = L;
            for (; R <= m; R++) {
                int e = r[R];
                int x = Find(u[e]), y = Find(v[e]);
                if (x != y) p[x] = y;
                if (jdg()) break;
            }
            if (R > m) break;
            ans = min(ans, w[r[R]] - w[r[L]]);
        }
        if (ans == INF) puts("-1");
        else printf("%d\n", ans);
    }

    return 0;
}


















































































