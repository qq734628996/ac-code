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
const int MAXN = 2e3+9, MAXM = 2e6+5, INF = 0x3f3f3f3f, MOD = 1000000000;

int f[MAXN],nxt[MAXM],to[MAXM],dis[MAXM],tot;
void init() { tot=0; memset(f,-1,sizeof(f)); }
void add(int u, int v, int w)
{
    to[tot]=v;
    dis[tot]=w;
    nxt[tot]=f[u];
    f[u]=tot++;
}
int n,m,d[MAXN];
priority_queue<pii> pq;
LL dij(int s, int t)
{
    while (!pq.empty()) pq.pop();
    memset(d,INF,sizeof(d));
    pq.push({d[s]=0,s});
    while (!pq.empty()) {
        int u=pq.top().se; pq.pop();
        for (int i=f[u]; ~i; i=nxt[i]) {
            int v=to[i],dist=dis[i];
            if (d[v]>d[u]+dist) {
                d[v]=d[u]+dist;
                pq.push({-d[v],v});
            }
        }
    }
    return d[t];
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
        printf("%d\n", dij(1,n));
    }

    return 0;
}




































