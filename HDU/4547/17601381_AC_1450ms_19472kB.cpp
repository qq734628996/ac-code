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
const int MAXN = 2e5+5, MAXM = 1e4+5, INF = 0x3f3f3f3f, MOD = 998244353;

struct edge {
    int to[MAXN],dist[MAXN],nxt[MAXN],f[MAXN],tot;
    bool flag[MAXN];
    void init()
    {
        tot=0;
        memset(f,-1,sizeof(f));
    }
    void add(int u, int v, int d=1, bool fl=false)
    {
        to[tot]=v;
        dist[tot]=d;
        flag[tot]=fl;
        nxt[tot]=f[u];
        f[u]=tot++;
    }
} e,q;

int p[MAXN];
int Find(int x) { return p[x]==x ? x : p[x]=Find(p[x]); }
void Union(int i, int j) { p[Find(i)]=Find(j); }

int d[MAXN];
void dfs(int rt)
{
    for (int i=e.f[rt]; ~i; i=e.nxt[i]) {
        d[e.to[i]]=d[rt]+1;
        dfs(e.to[i]);
    }
}

int n,m,rt,vis[MAXN],ans[MAXN];
void LCA(int rt)
{
    for (int i=e.f[rt]; ~i; i=e.nxt[i]) {
        LCA(e.to[i]);
        Union(e.to[i],rt);
    }
    vis[rt]=1;
    for (int i=q.f[rt]; ~i; i=q.nxt[i]) {
        if (vis[q.to[i]]) {
            int lca=Find(q.to[i]);
            if (!q.flag[i]) ans[q.dist[i]]=(q.to[i]!=lca)+d[rt]-d[lca];
            else ans[q.dist[i]]=(rt!=lca)+d[q.to[i]]-d[lca];
        }
    }
}

unordered_map<string, int> mp;
int cnt;
int ID(string& str)
{
    if (mp.count(str)) return mp[str];
    return mp[str]=cnt++;
}

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    int T; scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n,&m);

        e.init();
        q.init();
        REP(i,n) p[i]=i;
        memset(vis,0,sizeof(vis));
        mp.clear();
        cnt=0;

        REP(i,n-1) {
            string s,t; cin>>s>>t;
            int v=ID(s), u=ID(t);
            e.add(u,v);
            vis[v]=1;
        }
        REP(i,n) if (!vis[i]) rt=i;
        d[rt]=0;
        dfs(rt);
        REP(i,m) {
            string s,t; cin>>s>>t;
            int u=ID(s), v=ID(t);
            q.add(u,v,i,0);
            q.add(v,u,i,1);
        }

        memset(vis,0,sizeof(vis));
        LCA(rt);
        REP(i,m) printf("%d\n", ans[i]);
    }

    return 0;
}








































