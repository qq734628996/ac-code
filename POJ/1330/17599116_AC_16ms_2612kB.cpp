#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <ctime>
#include <cassert>

#include <iostream>
#include <algorithm>
//#include <unordered_map>
//#include <unordered_set>
#include <sstream>
#include <utility>
#include <string>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <set>
#include <map>
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
const int MAXN = 1e5+5, MAXM = 1e4+5, INF = 0x3f3f3f3f, MOD = 998244353;

struct Edge {
    int from[MAXN],to[MAXN],d[MAXN],f[MAXN],nxt[MAXN],tot;
    void init() {
        tot=0;
        memset(f,-1,sizeof(f));
    }
    void add(int u, int v, int dist) {
        from[tot]=u;
        to[tot]=v;
        d[tot]=dist;
        nxt[tot]=f[u];
        f[u]=tot++;
    }
} e,q;

int p[MAXN];
int Find(int x){ return p[x]==x?x:p[x]=Find(p[x]); }
void Union(int i, int j){ p[Find(i)]=Find(j); }

int n,m,rt,vis[MAXN],ans[MAXN];

void LCA(int rt)
{
    for (int i=e.f[rt]; ~i; i=e.nxt[i]) {
        LCA(e.to[i]);
        Union(e.to[i],rt);
    }
    vis[rt]=1;
    for (int i=q.f[rt]; ~i; i=q.nxt[i]) {
        if (vis[q.to[i]]) ans[q.d[i]]=Find(q.to[i]);
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
        int n; scanf("%d", &n);
        e.init();
        q.init();
        FOR(i,1,n) p[i]=i;
        memset(vis,0,sizeof(vis));
        REP(i,n-1) {
            int x,y; scanf("%d%d", &x,&y);
            e.add(x,y,1);
            vis[y]=1;
        }
        FOR(i,1,n) if (!vis[i]) rt=i;
        m=1;
        REP(i,m) {
            int x,y; scanf("%d%d", &x,&y);
            q.add(x,y,i); q.add(y,x,i);
        }
        memset(vis,0,sizeof(vis));
        LCA(rt);
        REP(i,m) printf("%d\n", ans[i]);
    }

    return 0;
}








































