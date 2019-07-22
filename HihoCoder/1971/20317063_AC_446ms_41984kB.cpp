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
const int MAXN = 1e3+9, MAXM = 2e6+9;

int to[MAXM],dis[MAXM],f[MAXN],nxt[MAXM],tot,vis[MAXM];
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
int n,m,d[MAXN];
void dij()
{
    memset(d,INF,sizeof(d));
    priority_queue<pii> pq;
    pq.push({d[1]=0,1});
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
int have[MAXN];
void bfs()
{
    memset(have,0,sizeof(have));
    queue<int> Q;
    Q.push(n); have[n]=1;
    while (!Q.empty()) {
        int u=Q.front(); Q.pop();
        for (int i=f[u]; ~i; i=nxt[i]) {
            int v=to[i], w=dis[i];
            if (d[v]==d[u]-w) {
                vis[i]=true;
                if (!have[v]) {
                    have[v]=1;
                    Q.push(v);
                }
            }
        }
    }
}

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    while (scanf("%d%d", &n,&m)==2) {
        init();
        REP(i,m) {
            int x,y,z; scanf("%d%d%d", &x,&y,&z);
            add(x,y,z);
            add(y,x,z);
        }
        dij();
        memset(vis,0,sizeof(vis));
        bfs();
        for (int i=0; i<tot; i+=2) {
            if (vis[i]||vis[i+1]) puts("YES");
            else puts("NO");
        }
    }

    return 0;
}

































