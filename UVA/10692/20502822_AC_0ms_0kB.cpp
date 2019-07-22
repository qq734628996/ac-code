#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i = 0; i < n; i++)
#define PER(i,n) for(int i = n-1; i >= 0; i--)
#define FOR(i,l,r) for(int i = l; i <= r; i++)
#define ROF(i,l,r) for(int i = r; i >= l; i--)
#define DEBUG(x) cout << #x << "=" << x << endl;
#define SHOW1(A,n) { REP(i,n) cout<<A[i]<<(i==n-1?'\n':' '); }
#define SHOW2(A,m,n) { REP(j,m) SHOW1(A[j],n) }
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
const int MAXN = 1e5+9, MAXM = 2e5+9;

int vis[MAXN],prime[MAXN],phi[MAXN],tot;
void getphi(int n)
{
    phi[1]=1;
    FOR(i,2,n) {
        if (!vis[i]) prime[tot++]=i, phi[i]=i-1;
        REP(j,tot) {
            if (i*prime[j]>n) break;
            vis[i*prime[j]]=1;
            if (i%prime[j]==0) {
                phi[i*prime[j]]=phi[i]*prime[j];
                break;
            } else phi[i*prime[j]]=phi[i]*(prime[j]-1);
        }
    }
}
LL powMod(LL x, LL e, LL mod)
{
    if (!e) return 1;
    return e&1 ? powMod(x,e-1,mod)*x%mod : powMod(x*x%mod,e>>1,mod);
}
int m,n,a[11],kase;
int calc(int i, int m)
{
    if (i==n-1) return a[i]%m;
    int e=calc(i+1,phi[m])+phi[m];
    return powMod(a[i],e,m);
}

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    getphi(MAXN-1);
    while (scanf("%d%d", &m,&n)==2) {
        REP(i,n) scanf("%d", &a[i]);
        printf("Case #%d: %d\n", ++kase,calc(0,m));
    }

    return 0;
}






























