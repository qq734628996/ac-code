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
const int MAXN = 1e4+5, MAXM = 3e1+5, INF = 0x3f3f3f3f, MOD = 1e9+7;

int n, c1, c2, p[MAXN], d[MAXN][2][2][2], vis[MAXN][2][2][2], is[MAXN], kase;
vector<int> E[MAXN];

void dfs(int u, int fa)
{
    p[u] = fa;
    bool isleaf = true;
    REP(v,SZ(E[u])) if (E[u][v] != fa) dfs(E[u][v], u), isleaf = false;
    if (isleaf) is[u] = kase;
}

int dp(int u, int i, int j, int k);
int cost(int x, int u, int i, int j, int k)
{
    REP(v,SZ(E[u])) if (E[u][v] != p[u]) x += dp(E[u][v],i,j,k);
    return x;
}

int dp(int u, int i, int j, int k)
{
    if (is[u] == kase) {
        if (!i) return c2;
        if (!j) return min(c1,c2);
        return 0;
    }
    int& ans = d[u][i][j][k];
    if (vis[u][i][j][k] == kase) return ans;
    vis[u][i][j][k] = kase;
    if (!i) ans = cost(c2,u,1,1,1);
    else if (!j) ans = min(min(cost(0,u,0,0,0), cost(c1,u,1,1,0)), dp(u,0,0,0));
    else if (!k) ans = min(cost(0,u,1,0,0), dp(u,1,0,0));
    else ans = min(cost(0,u,1,1,0), dp(u,1,1,0));
    int c = INF, x = cost(0,u,1,1,0);
    REP(v,SZ(E[u])) if (E[u][v] != p[u]) c = min(c, x-dp(E[u][v],1,1,0)+dp(E[u][v],0,0,0));
    if (i) ans = min(ans, c);
    return ans;
}

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    while (~scanf("%d%d%d", &n, &c1, &c2)) {
        if (!n && !c1 && !c2) break;
        ++kase;
        FOR(i,1,n) E[i].clear();
        REP(i,n-1) {
            int x, y; scanf("%d%d", &x, &y);
            E[x].pb(y); E[y].pb(x);
        }
        dfs(1,0);
        printf("%d\n", dp(1,1,1,0));
    }

    return 0;
}














































































