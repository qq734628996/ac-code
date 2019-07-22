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
const int MAXN = 2e3+9, MAXM = 1e4+5;

int n,m,st,ed,d1[MAXN],d2[MAXN],fa1[MAXN],fa2[MAXN],kase;
int to[MAXN],dis[MAXN],f[MAXN],nxt[MAXN],tot;
void add(int u, int v, int w)
{
    to[tot]=v;
    dis[tot]=w;
    nxt[tot]=f[u];
    f[u]=tot++;
}
void init()
{
    tot=0;
    memset(f,-1,sizeof(f));
}
void dij(int s, int d[MAXN], int fa[MAXN]/*unnecessary*/)
{
    memset(d,INF,sizeof(int)*(n+1));
    priority_queue<pii> pq;
    pq.push({d[s]=0,s});
    while (!pq.empty()) {
        int u=pq.top().se; pq.pop();
        for (int i=f[u]; ~i; i=nxt[i]) {
            int v=to[i], w=dis[i];
            if (d[v]>d[u]+w) {
                d[v]=d[u]+w;
                fa[v]=u; // unnecessary
                pq.push({-d[v],v});
            }
        }
    }
}
int ans[MAXN];

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    freopen("o.txt", "w", stdout);
#endif //LOCAL

    while (scanf("%d%d%d", &n,&st,&ed)==3) {
        init();
        scanf("%d", &m);
        REP(i,m) {
            int x,y,z; scanf("%d%d%d", &x,&y,&z);
            add(x,y,z), add(y,x,z);
        }
        dij(st,d1,fa1);
        dij(ed,d2,fa2);
        int minT=d1[ed],ansX=-1,ansY;
        scanf("%d", &m);
        REP(i,m) {
            int x,y,z; scanf("%d%d%d", &x,&y,&z);
            if (minT>d1[x]+d2[y]+z) {
                minT=d1[x]+d2[y]+z;
                ansX=x, ansY=y;
            }
            swap(x,y);
            if (minT>d1[x]+d2[y]+z) {
                minT=d1[x]+d2[y]+z;
                ansX=x, ansY=y;
            }
        }
        int cnt=0;
        stack<int> stk;
        if (ansX==-1) {
            for (int u=ed; u!=st; u=fa1[u]) {
                stk.push(u);
            }
            ans[cnt++]=st;
            while (!stk.empty()) {
                ans[cnt++]=stk.top(); stk.pop();
            }
        } else {
            for (int u=ansX; u!=st; u=fa1[u]) {
                stk.push(u);
            }
            ans[cnt++]=st;
            while (!stk.empty()) {
                ans[cnt++]=stk.top(); stk.pop();
            }
            for (int u=ansY; u!=ed; u=fa2[u]) {
                ans[cnt++]=u;
            }
            ans[cnt++]=ed;
        }
        if (kase++) puts("");
        REP(i,cnt) printf("%d%c", ans[i],i==cnt-1?'\n':' ');
        if (ansX==-1) puts("Ticket Not Used");
        else printf("%d\n", ansX);
        printf("%d\n", minT);
    }

    return 0;
}

































