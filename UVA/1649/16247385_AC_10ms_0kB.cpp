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

double fac[35];
typedef pair<LL, LL> pll;

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    freopen("o.txt", "w", stdout);
#endif //LOCAL

    fac[0] = 1; FOR(i,1,30) fac[i] = fac[i-1]*i;
    int T; scanf("%d", &T);
    while (T--) {
        LL m; scanf("%lld", &m);
        set<pll> ans;
        ans.insert(pll(m,1));
        ans.insert(pll(m,m-1));
        FOR(k,1,30) {
            double t = m*fac[k];
            t = pow(t, 1.0/k);
            int n = max(1, (int)t);
            REP(i,30) {
                if (n+i < k) continue;
                LL res = 1;
                FOR(j,1,k) {
                    res = res*(n+i-j+1)/j;
                    if (res < 0 || res > 1e15) break;
                }
                if (res == m) {
                    ans.insert(pll(n+i,k));
                    ans.insert(pll(n+i,n+i-k));
                }
            }
        }
        printf("%d", SZ(ans));
        bool first = true;
        for (auto& i:ans) {
            if (first) putchar('\n'), first = false;
            else putchar(' ');
            printf("(%lld,%lld)", i.fi, i.se);
        }
        puts("");
    }

    return 0;
}












































































