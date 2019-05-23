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
const int MAXN = 1e5+5, MAXM = 1e5+5, INF = 0x3f3f3f3f, MOD = 1e8+7;

typedef pair<LL, LL> pll;
LL a[MAXN];
LL gcd(LL a, LL b) { return b == 0 ? a : gcd(b, a%b); }

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    freopen("o.txt", "w", stdout);
#endif //LOCAL

    int T; scanf("%d", &T);
    while (T--) {
        int n; scanf("%d", &n);
        REP(i,n) scanf("%lld", &a[i]);
        LL ans = 0;
        vector<pll> V[2];
        int t = 0;
        REP(i,n) {
            LL pre = 0;
            V[t].clear();
            for (auto& j : V[t^1]) {
                LL g = gcd(j.fi, a[i]);
                if (g > pre) {
                    pre = g;
                    V[t].pb(pll(g, j.se));
                }
            }
            if (a[i] > pre) V[t].pb(pll(a[i],i));
            for (auto& j : V[t]) {
                ans = max(ans, (i-j.se+1)*j.fi);
            }
            t ^= 1;
        }
        printf("%lld\n", ans);
    }

    return 0;
}













































































