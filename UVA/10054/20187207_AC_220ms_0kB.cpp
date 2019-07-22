#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i = 0; i < n; i++)
#define PER(i,n) for(int i = n-1; i >= 0; i--)
#define FOR(i,l,r) for(int i = l; i <= r; i++)
#define ROF(i,l,r) for(int i = r; i >= l; i--)
#define DEBUG(x) cout << #x << "=" << x << endl;
#define SHOW1(A,n) { REP(i,n-1) printf("%d ", A[i]); printf("%d\n", A[n-1]); }
#define SHOW2(A,m,n) { REP(i,m) { REP(j,n-1) printf("%d ", A[i][j]); printf("%d\n", A[i][n-1]); } }
#define pb push_back
#define fi first
#define se second
#define ALL(x) x.begin(),x.end()
#define SZ(x) (int)((x).size())
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;
const int INF = 0x3f3f3f3f, MOD = 1000000007;
const double EPS = 1e-14;
const int MAXN = 5e1+9, MAXM = 1e4+5;

int n,g[MAXN][MAXN],deg[MAXN],vis[MAXN],vis1[MAXN][MAXN],kase;
void dfs(int u)
{
    vis[u]=1;
    FOR(v,1,50) if (g[u][v] && !vis[v]) dfs(v);
}
bool jdg()
{
    FOR(i,1,50) if (deg[i]&1) return false;
    memset(vis,0,sizeof(vis));
    FOR(i,1,50) if (deg[i]) { dfs(i); break; }
    FOR(i,1,50) if (deg[i] && !vis[i]) return false;
    return true;
}
stack<pii> ans;
void euler(int u)
{
    FOR(v,1,50) if (g[u][v] && vis1[u][v]<g[u][v]) {
        vis1[u][v]++, vis1[v][u]++;
        euler(v);
        ans.push({u,v});
    }
}

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    int T; scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        memset(g,0,sizeof(g));
        memset(deg,0,sizeof(deg));
        REP(i,n) {
            int x,y; scanf("%d%d", &x,&y);
            deg[x]++, deg[y]++;
            g[x][y]++, g[y][x]++;
        }
        if (kase++) puts("");
        printf("Case #%d\n", kase);
        if (!jdg()) puts("some beads may be lost");
        else {
            memset(vis1,0,sizeof(vis1));
            while (!ans.empty()) ans.pop();
            FOR(i,1,50) if (deg[i]) {
                euler(i);
                break;
            }
            while (!ans.empty()) {
                pii now=ans.top(); ans.pop();
                printf("%d %d\n", now.fi,now.se);
            }
        }
    }

    return 0;
}


































