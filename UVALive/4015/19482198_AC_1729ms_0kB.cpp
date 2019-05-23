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
const int MAXN = 1e3+5, MAXM = 5e3+5, INF = 0x3f3f3f3f, MOD = 10007;

int to[MAXN],f[MAXN],nxt[MAXN],dis[MAXN],tot;
void add(int u, int v, int dist)
{
    to[tot]=v;
    dis[tot]=dist;
    nxt[tot]=f[u];
    f[u]=tot++;
}
int n,q,cnt[MAXN],kase;
LL d[MAXN][MAXN],g[MAXN][MAXN];
void dp(int u, int fa)
{
    for (int i=f[u]; ~i; i=nxt[i]) if (to[i]!=fa) {
        int v=to[i], w=dis[i];
        dp(v,u);
        ROF(i,2,n)FOR(j,1,i-1) {
            d[u][i]=min(d[u][i], min(d[u][i-j]+g[v][j]+2*w, d[v][j]+g[u][i-j]+w));
            g[u][i]=min(g[u][i], g[u][i-j]+g[v][j]+2*w);
        }
    }
}

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    while (scanf("%d", &n)==1 && n) {
        printf("Case %d:\n", ++kase);
        tot=0;
        memset(f,-1,sizeof(f));
        REP(i,n-1) {
            int x,y,z; scanf("%d%d%d", &x,&y,&z);
            add(x,y,z); add(y,x,z);
        }
        memset(d,INF,sizeof(d));
        memset(g,INF,sizeof(g));
        REP(i,n) d[i][1]=g[i][1]=0;
        dp(0,-1);
        scanf("%d", &q);
        while (q--) {
            int x; scanf("%d", &x);
            int ans=1;
            FOR(i,2,n) {
                if (d[0][i]<=x) ans=i;
                else break;
            }
            printf("%d\n", ans);
        }
    }

    return 0;
}





































