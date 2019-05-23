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
const int MAXN  = 1e2+5, INF = ~0U>>1;

int n, m, G[MAXN][MAXN], vis[MAXN];

bool dfs(int i)
{
    vis[i] = -1;
    FOR(j,1,n)if(G[i][j])if(vis[j]<0 || (!vis[j] && !dfs(j))) return false;
    vis[i] = 1;
    return true;
}

bool toposort()
{
    memset(vis, 0, sizeof(vis));
    FOR(i,1,n)if(!vis[i] && !dfs(i)) return false;
    return true;
}

int main()
{
#ifdef LOCAL
    //freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    while (~scanf("%d%d", &n, &m)) {
        memset(G, 0, sizeof(G));
        REP(i,m) {
            int x, y; scanf("%d%d", &x, &y);
            G[x][y] = 1;
        }

        puts(toposort() ? "YES" : "NO");
    }

    return 0;
}



































