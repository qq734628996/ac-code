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
const int MAXN = 1e5+5, MAXM = 5e3+5, INF = 0x3f3f3f3f, MOD = 1000000007;

int to[MAXN],f[MAXN],nxt[MAXN],tot;
inline void add(int u, int v)
{
    to[tot]=v;
    nxt[tot]=f[u];
    f[u]=tot++;
}
int n,m,vis[MAXN],s[MAXN];
void dfs(int u)
{
    s[u]=1;
    for (int i=f[u]; ~i; i=nxt[i]) {
        int v=to[i];
        dfs(v);
        s[u]+=s[v];
    }
}
LL fac[MAXN];
void ex_gcd(LL a, LL b, LL& d, LL& x, LL& y)
{
    if (!b) x=1, y=0, d=a;
    else ex_gcd(b,a%b,d,y,x), y-=x*(a/b);
}
LL inv(LL a, LL p)
{
    LL d,x,y;
    ex_gcd(a,p,d,x,y);
    return d==1 ? (x+p)%p : -1;
}

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    freopen("o.txt", "w", stdout);
#endif //LOCAL

    fac[1]=1;
    FOR(i,2,40000) fac[i]=(fac[i-1]*i)%MOD;
    int T; scanf("%d", &T);
    while (T--) {
        tot=0;
        memset(f,-1,sizeof(f));
        memset(vis,0,sizeof(vis));
        scanf("%d%d", &n,&m);
        REP(i,m) {
            int x,y; scanf("%d%d", &x,&y);
            add(y,x);
            vis[x]=1;
        }
        FOR(i,1,n) if (!vis[i]) add(0,i);
        dfs(0);
        LL ans=fac[n];
        FOR(i,1,n) ans=(ans*inv(s[i],MOD))%MOD;
        printf("%lld\n", ans);
    }

    return 0;
}




































