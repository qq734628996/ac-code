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
const int MAXN = 1e2+9, MAXM = 2e3+9;

const LL LINF=0x3f3f3f3f3f3f3f3f;
int to[MAXM],dis[MAXM],f[MAXN],nxt[MAXM],tot;
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
int n,m,L,p[MAXN][MAXN];
LL d[MAXN][MAXN],g[MAXN],C[MAXN];
void dij(int s, LL d[MAXN], int p[MAXN], int eid)
{
    memset(d,INF,sizeof(LL)*(n+1));
    memset(p,-1,sizeof(int)*(n+1));
    priority_queue<pll> pq;
    pq.push({d[s]=0,s});
    while (!pq.empty()) {
        int u=pq.top().se; pq.pop();
        for (int i=f[u]; ~i; i=nxt[i]) {
            if (i/2*2==eid) continue;
            int v=to[i], w=dis[i];
            if (d[v]>d[u]+w) {
                d[v]=d[u]+w;
                p[v]=i/2*2;
                pq.push({-d[v],v});
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

    while (scanf("%d%d%d", &n,&m,&L)==3) {
        init();
        REP(i,m) {
            int x,y,z; scanf("%d%d%d", &x,&y,&z);
            add(x,y,z), add(y,x,z);
        }
        FOR(i,1,n) dij(i,d[i],p[i],-1);
        LL oldC=0,newC=0;
        FOR(i,1,n) {
            C[i]=0;
            FOR(j,1,n) C[i]+=d[i][j]==LINF?L:d[i][j];
            oldC+=C[i];
        }
        REP(k,tot) if (k%2==0) {
            LL t=0;
            FOR(i,1,n) {
                bool flag=true;
                FOR(j,1,n) if (p[i][j]==k){ flag=false; break; }
                if (flag) t+=C[i];
                else {
                    dij(i,g,p[0],k);
                    FOR(j,1,n) t+=g[j]==LINF?L:g[j];
                }
            }
            newC=max(newC,t);
        }
        printf("%lld %lld\n", oldC,newC);
    }

    return 0;
}

































