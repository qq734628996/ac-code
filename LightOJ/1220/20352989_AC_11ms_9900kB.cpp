#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i = 0; i < n; i++)
#define PER(i,n) for(int i = n-1; i >= 0; i--)
#define FOR(i,l,r) for(int i = l; i <= r; i++)
#define ROF(i,l,r) for(int i = r; i >= l; i--)
#define DEBUG(x) cout << #x << "=" << x << endl;
#define SHOW1(A,n) { REP(i,n) printf("%d%c", A[i],i==n-1?'\n':' '); }
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
const int MAXN = 1e6+9, MAXM = 3e3+9;

int vis[MAXN],prime[MAXN],tot;
void getPrime(int n)
{
    FOR(i,2,n) {
        if (!vis[i]) prime[tot++]=i;
        REP(j,tot) {
            if (i*prime[j]>n) break;
            vis[i*prime[j]]=1;
            if (i%prime[j]==0) break;
        }
    }
}
vector<pll> e;
void gete(LL n)
{
    e.clear();
    REP(i,tot) {
        if ((LL)prime[i]*prime[i]>n) break;
        int cnt=0;
        while (n%prime[i]==0) {
            cnt++;
            n/=prime[i];
        }
        if (cnt) e.pb({prime[i],cnt});
    }
    if (n!=1) e.pb({n,1});
}
LL gcd(LL a, LL b){ return b==0?a:gcd(b,a%b); }

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    freopen("o.txt", "w", stdout);
#endif //LOCAL

    getPrime(MAXN-1);
    int T; scanf("%d", &T);
    FOR(kase,1,T) {
        LL n; scanf("%lld", &n);
        bool sign=false;
        if (n<0) n=-n, sign=true;
        gete(n);
        LL ans=e[0].se;
        FOR(i,1,SZ(e)-1) ans=gcd(ans,e[i].se);
        if (sign) {
            while (ans%2==0) ans/=2;
        }
        printf("Case %d: %lld\n", kase,ans);
    }

    return 0;
}


































