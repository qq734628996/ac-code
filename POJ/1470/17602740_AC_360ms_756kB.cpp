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
const int MAXN = 2e3+5, MAXM = 1e4+5, INF = 0x3f3f3f3f, MOD = 998244353;

struct edge {
    int to[MAXN],nxt[MAXN],f[MAXN],tot;
    void init()
    {
        tot=0;
        memset(f,-1,sizeof(f));
    }
    void add(int u, int v)
    {
        to[tot]=v;
        nxt[tot]=f[u];
        f[u]=tot++;
    }
} e;

int d[MAXN],l[MAXN],r[MAXN],euler[MAXN],cnt;
void dfs(int rt)
{
    l[rt]=++cnt;
    euler[cnt]=rt;
    for (int i=e.f[rt]; ~i; i=e.nxt[i]) {
        d[e.to[i]]=d[rt]+1;
        dfs(e.to[i]);
        euler[++cnt]=rt;
    }
    r[rt]=cnt;
}

int dp[MAXN][10];
inline int Min(int i, int j) { return d[i]<d[j] ? i : j; }
void RMQ_init()
{
    FOR(i,1,cnt) dp[i][0]=euler[i];
    for (int j=1; (1<<j) < cnt; j++) {
        for (int i=1; i+(1<<j)-1 <= cnt; i++) {
            dp[i][j]=Min(dp[i][j-1], dp[i+(1<<(j-1))][j-1]);
        }
    }
}
int RMQ(int L, int R)
{
    int k=0;
    while ((1<<(k+1)) <= R-L+1) k++;
    return Min(dp[L][k], dp[R-(1<<k)+1][k]);
}

int n,m,rt,vis[MAXN],ans[MAXN];

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    while (~scanf("%d", &n)) {
        e.init();
        cnt=0;
        memset(vis,0,sizeof(vis));
        memset(ans,0,sizeof(ans));
        REP(i,n) {
            int u,v,x;
            scanf("%d", &u);
            while (getchar()!=':');
            while (getchar()!='(');
            scanf("%d", &x);
            while (getchar()!=')');
            REP(j,x) {
                scanf("%d", &v);
                e.add(u,v);
                vis[v]=1;
            }
        }
        FOR(i,1,n) if (!vis[i]) rt=i;
        d[rt]=0;
        dfs(rt);
        RMQ_init();
        scanf("%d", &m);
        REP(i,m) {
            int u,v;
            while (getchar()!='(');
            scanf("%d%d", &u,&v);
            while (getchar()!=')');
            ans[RMQ(min(l[u],l[v]), max(l[u],l[v]))]++;
        }
        FOR(i,1,n) if (ans[i]) printf("%d:%d\n", i,ans[i]);
    }

    return 0;
}







































