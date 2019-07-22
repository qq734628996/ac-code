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
const double PI = acos(-1), EPS = 1e-15;
const int MAXN = 1e6+9, MAXM = 1e4+5;

int to[MAXN],dis[MAXN],f[MAXN],nxt[MAXN],tot;
void init()
{
    tot=0;
    memset(f,-1,sizeof(f));
}
void add(int u, int v, int w)
{
    to[tot]=v;
    dis[tot]=w;
    nxt[tot]=f[u];
    f[u]=tot++;
}
int n,m;
LL d[MAXN],g[MAXN],vis[MAXN];
void dij(int s)
{
    memset(d,INF,sizeof(d));
    priority_queue<pll> pq;
    pq.push({d[s]=0,s});
    while (!pq.empty()) {
        int u=pq.top().se; pq.pop();
        for (int i=f[u]; ~i; i=nxt[i]) {
            int v=to[i], w=dis[i];
            if (d[v]>d[u]+w) {
                d[v]=d[u]+w;
                pq.push({-d[v],v});
            }
        }
    }
}
LL dp(int u)
{
    if (u==2) return 1;
    if (vis[u]) return g[u];
    vis[u]=1;
    g[u]=0;
    for (int i=f[u]; ~i; i=nxt[i]) {
        int v=to[i], w=dis[i];
        if (d[v]<d[u]) {
            g[u]+=dp(v);
        }
    }
    return g[u];
}

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    while (scanf("%d%d", &n,&m)==2 && n) {
        init();
        REP(i,m) {
            int x,y,z; scanf("%d%d%d", &x,&y,&z);
            add(x,y,z);
            add(y,x,z);
        }
        dij(2);
        memset(vis,0,sizeof(vis));
        printf("%lld\n", dp(1));
    }

    return 0;
}
































