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
const int MAXN  = 1e4+5, INF = 0x3f3f3f3f, MOD = 998244353;

int n, d[MAXN][3], x, y;
vector<int> E[MAXN];

int dp(int u, int st, int fa)
{
    int& ans = d[u][st];
    if (ans != -1) return ans;
    ans = !st;
    if (fa && SZ(E[u]) == 1) {
        if (st == 2) return ans = INF;
        return ans;
    }
    if (st == 0) {
        for (auto& v:E[u]) if (v != fa) ans += min(dp(v,0,u), dp(v,1,u));
    } else if (st == 1) {
        for (auto& v:E[u]) if (v != fa) {
            if (dp(v,2,u) == INF) { ans = INF; break; }
            ans += dp(v,2,u);
        }
    } else {
        ans = INF;
        int cnt = 0;
        for (auto& v:E[u]) if (v != fa) {
            if (dp(v,2,u) == INF) cnt++;
            ans = min(ans, dp(u,1,fa)-dp(v,2,u)+dp(v,0,u));
        }
        if (cnt >= 2) ans = INF;
    }
    return ans;
}

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    freopen("o.txt", "w", stdout);
#endif //LOCAL

    while (~scanf("%d", &n)) {
        FOR(i,1,n) E[i].clear();
        memset(d, -1, sizeof(d));
        FOR(i,2,n) scanf("%d%d",&x,&y), E[x].pb(y), E[y].pb(x);
        printf("%d\n", min(dp(1,0,0), dp(1,2,0)));
        //FOR(i,1,n)REP(j,3) printf("%d %d %d\n", i, j, d[i][j]);
        scanf("%d", &n);
    }

    return 0;
}




















































































