#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i = 0; i < n; i++)
#define PER(i,n) for(int i = n-1; i >= 0; i--)
#define FOR(i,l,r) for(int i = l; i <= r; i++)
#define ROF(i,l,r) for(int i = r; i >= l; i--)
#define TR(e,x) for(auto e = x.begin(); e != x.end(); e++)
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
const int MAXN = 1e5+5, MAXM = 1e5+5, INF = 0x3f3f3f3f, MOD = 1e9+7;

typedef unsigned long long ull;
typedef long double ld;
ull seed;
ld gen()
{
    static const ld Z = (ld)1/(1LL<<32);
    static const ull T = (1ULL<<32)-1;
    seed = ((seed>>16)&T);
    seed *= seed;
    return seed*Z;
}
ld sqr(ld x) { return x*x; }

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    int T; scanf("%d", &T);
    FOR(kase,1,T) {
        int n; ull s; scanf("%d%llu", &n, &s);
        seed = s;
        ld m = 0;
        REP(i,n) m += gen();
        m /= n;
        ld ans = 0;
        seed = s;
        REP(i,n) ans += sqr(gen()-m);
        printf("Case #%d: %.5Lf\n", kase, sqrt(ans/n));
    }

    return 0;
}













































































