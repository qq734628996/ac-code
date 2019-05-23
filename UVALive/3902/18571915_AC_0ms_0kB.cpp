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
typedef pair<int, int> pii;
const int MAXN = 2e3+5, MAXM = 1e4+5, INF = 0x3f3f3f3f, MOD = 998244353;

int to[MAXN],f[MAXN],nxt[MAXN],tot;
inline void add(int u, int v)
{
    to[tot]=v;
    nxt[tot]=f[u];
    f[u]=tot++;
}
int n,root,K,vis[MAXN],maxd,fa[MAXN];
vector<int> dep[MAXN];
#define isleaf(i) (nxt[f[i]]==-1)
void dfs1(int rt, int cnt, int p)
{
    fa[rt]=p;
    maxd=max(maxd,cnt);
    dep[cnt].pb(rt);
    if (isleaf(rt) && cnt<=K) vis[rt]=1;
    for (int i=f[rt]; ~i; i=nxt[i]) if (to[i]!=p) {
        dfs1(to[i],cnt+1,rt);
    }
}
void dfs2(int rt, int cnt, int p)
{
    if (cnt>K) return;
    if (isleaf(rt)) vis[rt]=1;
    for (int i=f[rt]; ~i; i=nxt[i]) if (to[i]!=p) {
        dfs2(to[i],cnt+1,rt);
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
        memset(f,-1,sizeof(f));
        tot=0;
        scanf("%d%d%d", &n,&root,&K);
        REP(i,n-1) {
            int x,y; scanf("%d%d", &x,&y);
            add(x,y); add(y,x);
        }
        memset(vis,0,sizeof(vis));
        REP(i,n) dep[i].clear();
        maxd=0;
        dfs1(root,0,-1);
        int ans=0;
        ROF(i,0,maxd)REP(j,SZ(dep[i])) {
            int r=dep[i][j];
            if (isleaf(r) && !vis[r]) {
                int x=r;
                REP(k,K) x=fa[x];
                dfs2(x,0,-1);
                ans++;
            }
        }
        printf("%d\n", ans);
    }

    return 0;
}










































