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
const int MAXN = 5e5+9, MAXM = 1e4+5;

int n,m,s[MAXN];
int out[MAXN],fa[MAXN];
void bfs()
{
    queue<int> Q;
    FOR(i,1,n) {
        s[i]=1;
        if (!out[i]) Q.push(i);
    }
    while (!Q.empty()) {
        int u=Q.front(); Q.pop();
        if (u==1) continue;
        s[fa[u]]+=s[u];
        if (--out[fa[u]]==0) Q.push(fa[u]);
    }
}
int vis[MAXN],prime[MAXN],tot,pos[MAXN];
void getPrime(int n)
{
    FOR(i,2,n) {
        if (!vis[i]) pos[i]=tot, prime[tot++]=i;
        REP(j,tot) {
            if (i*prime[j]>n) break;
            vis[i*prime[j]]=1;
            if (i%prime[j]==0) break;
        }
    }
}
int e[42000];
void add_int(int n, int d)
{
    REP(i,tot) {
        if (prime[i]*prime[i]>n || n==1) break;
        while (n%prime[i]==0) {
            n/=prime[i];
            e[i]+=d;
        }
    }
    if (n!=1) e[pos[n]]+=d;
}
LL powMod(LL x, LL e)
{
    LL res=1,bas=x;
    while (e) {
        if (e&1) res=res*bas%m;
        bas=bas*bas%m;
        e>>=1;
    }
    return res;
}

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    getPrime(MAXN-1);
    int T; scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n,&m);
        memset(out+1,0,sizeof(int)*n);
        REP(i,n-1) {
            int x; scanf("%d", &x);
            fa[i+2]=x;
            out[x]++;
        }
        bfs();
        memset(e,0,sizeof(e));
        FOR(i,2,n-1) add_int(i,1);
        FOR(i,2,n) add_int(s[i],-1);
        LL ans=1;
        REP(i,tot) if (e[i]) ans=ans*powMod(prime[i],e[i])%m;
        printf("%lld\n", ans);
    }

    return 0;
}


































