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
const int INF = 0x3f3f3f3f, MOD = 1000003;
const double PI = acos(-1), EPS = 1e-15;
const int MAXN = 1e6+9, MAXM = 3e3+9;

LL powMod(LL x, LL e)
{
    if (!e) return 1;
    return e&1 ? powMod(x,e-1)*x%MOD : powMod(x*x%MOD,e>>1);
}
LL fac[MAXN],inv[MAXN];
void getinv(int n)
{
    fac[0]=1;
    FOR(i,1,n) fac[i]=fac[i-1]*i%MOD;
    inv[n]=powMod(fac[n],MOD-2);
    ROF(i,0,n-1) inv[i]=inv[i+1]*(i+1)%MOD;
}

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    getinv(1000000);
    int T; scanf("%d", &T);
    FOR(kase,1,T) {
        int n,k; scanf("%d%d", &n,&k);
        printf("Case %d: %lld\n", kase,fac[n]*inv[n-k]*inv[k]%MOD);
    }

    return 0;
}


































