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
const int MAXN = 1e4+5, MAXM = 5e3+5, INF = 0x3f3f3f3f, MOD = 10007;

int to[MAXN],f[MAXN],nxt[MAXN],tot;
void add(int u, int v)
{
    to[tot]=v;
    nxt[tot]=f[u];
    f[u]=tot++;
}
int n,d[MAXN][2],vis[MAXN][2];
int dp(int u, int st, int fa)
{
    int& ans=d[u][st];
    if (vis[u][st]) return ans;
    vis[u][st]=1;
    ans=INF;
    if (st) {
        int cnt=0;
        for (int i=f[u]; ~i; i=nxt[i]) if (to[i]!=fa) {
            int v=to[i];
            cnt+=dp(v,0,u);
        }
        ans=min(ans, cnt);
    }
    int cnt=1;
    for (int i=f[u]; ~i; i=nxt[i]) if (to[i]!=fa) {
        int v=to[i];
        cnt+=dp(v,1,u);
    }
    return ans=min(ans, cnt);
}

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    while (scanf("%d", &n)==1) {
        tot=0;
        memset(f,-1,sizeof(f));
        REP(i,n) {
            int u,cnt; scanf("%d:(%d)", &u,&cnt);
            REP(j,cnt) {
                int v; scanf("%d", &v);
                add(u,v); add(v,u);
            }
        }
        memset(vis,0,sizeof(vis));
        printf("%d\n", dp(0,1,-1));
    }

    return 0;
}






































