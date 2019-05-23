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
const int MAXN  = 1e3+5, INF = ~0U>>1, MOD = ~0U>>1, EPS = 1e-8;

int n,m,cnt,vis[MAXN];
vector<int> E[MAXN];

void dfs(int u, int id)
{
    vis[u] = id;
    REP(v,SZ(E[u]))if(!vis[E[u][v]])dfs(E[u][v],id);
}

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    while (scanf("%d%d", &n,&m), n) {
        FOR(i,1,n)E[i].clear();
        memset(vis+1,0,sizeof(int)*n);
        cnt = 0;

        while (m--) {
            int x,y;scanf("%d%d", &x,&y);
            E[x].push_back(y);
            E[y].push_back(x);
        }

        FOR(i,1,n)if(!vis[i]) dfs(i,++cnt);

        printf("%d\n", cnt-1);
    }

    return 0;
}

































