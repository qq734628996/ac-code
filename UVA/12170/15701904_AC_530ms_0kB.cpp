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
const int MAXN = 1e2+5, MAXM = 3e3+5, INF = 0x3f3f3f3f, MOD = 1e9+7;

int T, n, d, h[MAXN], tot, deq[MAXN*MAXN*2];
LL a[MAXN*MAXN*2], dp[MAXN][MAXN*MAXN*2];
set<LL> S;

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    freopen("o.txt", "w", stdout);
#endif //LOCAL

    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n, &d);
        REP(i,n) scanf("%d", &h[i]);
        S.clear();
        REP(i,n)REP(j,n) S.insert(h[i]+j*(LL)d), S.insert(h[i]-j*(LL)d);
        tot = 0;
        for (auto& i:S) if (i >= 0) a[tot++] = i;
        REP(i,n)REP(j,tot) dp[i][j] = 1e17;
        dp[0][lower_bound(a, a+tot, h[0])-a] = 0;
        FOR(i,1,n-1) {
            int ed = 0, l = 0, r = 0;
            REP(j,tot) {
                while (ed < tot && a[ed] <= a[j]+d) {
                    while (l < r && dp[i-1][deq[r-1]] >= dp[i-1][ed]) r--;
                    deq[r++] = ed;
                    ed++;
                }
                while (l < r && a[deq[l]] < a[j]-d) l++;
                if (l < r) dp[i][j] = min(dp[i][j], abs(h[i]-a[j])+dp[i-1][deq[l]]);
            }
        }
        LL ans = dp[n-1][lower_bound(a, a+tot, h[n-1]) - a];
        if (ans == 1e17) puts("impossible");
        else printf("%lld\n", ans);
    }

    return 0;
}


















































































