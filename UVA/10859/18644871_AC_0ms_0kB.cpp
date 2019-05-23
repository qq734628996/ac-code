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
void add(int u, int v)
{
    to[tot]=v;
    nxt[tot]=f[u];
    f[u]=tot++;
}
int n,m,d[MAXN][2],vis[MAXN][2],kase;
int dp(int i, int j, int fa)
{
    int& ans=d[i][j];
    if (vis[i][j]==kase) return ans;
    vis[i][j]=kase;
    ans=2000;
    for (int u=f[i]; ~u; u=nxt[u]) if (to[u]!=fa) {
        ans+=dp(to[u],1,i);
    }
    if (!j && ~fa) ans++;
    if (j || fa==-1) {
        int sum=0;
        for (int u=f[i]; ~u; u=nxt[u]) if (to[u]!=fa) {
            sum+=dp(to[u],0,i);
        }
        if (~fa) sum++;
        ans=min(ans,sum);
    }
    return ans;
}

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    int T; scanf("%d", &T);
    while (T--) {
        kase++;
        scanf("%d%d", &n,&m);
        memset(f,-1,sizeof(f));
        tot=0;
        REP(i,m) {
            int x,y; scanf("%d%d", &x,&y);
            add(x,y); add(y,x);
        }
        int ans=0;
        REP(i,n) if (vis[i][0]!=kase) {
            ans+=dp(i,0,-1);
        }
        printf("%d %d %d\n", ans/2000,m-ans%2000,ans%2000);
    }

    return 0;
}










































