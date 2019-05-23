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
const int MAXN = 1e2+5, MAXM = 1e2+5, INF = 0x3f3f3f3f, MOD = 1e4+1;

void ex_gcd(LL a, LL b, LL& d, LL& x, LL& y)
{
    if (!b) { x = 1; y = 0; d = a; }
    else { ex_gcd(b, a%b, d, y, x); y -= x*(a/b); }
}

int n;
LL b, y, d, x[MAXN], ans[MAXN];

bool jdg(int a)
{
    REP(i,n) ans[i] = (a*x[i]+b)%MOD;
    FOR(i,1,n-1) if (x[i] != (a*ans[i-1]+b)%MOD) return false;
    return true;
}

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    while (~scanf("%d", &n)) {
        REP(i,n) scanf("%lld", &x[i]);
        FOR(a,0,MOD) {
            ex_gcd(a+1,MOD,d,b,y);
            if ((x[1] - x[0]*a*a) % d == 0) {
                b = (b*((x[1] - x[0]*a*a)/d))%MOD;
                b = (b+MOD)%MOD;
                if (jdg(a)) break;
            }
        }
        REP(i,n) printf("%lld\n", ans[i]);
    }

    return 0;
}














































































