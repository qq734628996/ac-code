#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i = 0; i < n; i++)
#define FOR(i,l,r) for(int i = l; i <= r; i++)
#define TR(e,x) for(auto e = x.begin(); e != x.end(); e++)
#define DEBUG(x) cout << #x << "=" << x << endl;
#define SHOW1(A,n) { REP(i,n-1) printf("%d ", A[i]); printf("%d\n", A[n-1]); }
#define SHOW2(A,m,n) { REP(i,m) { REP(j,n-1) printf("%d ", A[i][j]); printf("%d\n", A[i][n-1]); } }
#define PB push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) (int)((x).size())
typedef long long LL;
typedef pair<int, int> pii;
const int MAXN  = 1e6+5, INF = ~0U>>1, MOD = ~0U>>1;

int T, n, m, k, a[MAXN], vis[105], kase;

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    freopen("o.txt", "w", stdout);
#endif //LOCAL

    FOR(i,1,3) a[i] = i;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d%d", &n, &m, &k);
        FOR(i,4,n) a[i] = (a[i-1]+a[i-2]+a[i-3])%m+1;
        int l = 1, r = 1, ans = INF, cnt = 0;
        memset(vis, 0, sizeof(vis));
        while (r <= n) {
            for ( ; r <= n && cnt < k; r++) {
                if (a[r] <= k) {
                    if (!vis[a[r]]) cnt++;
                    vis[a[r]]++;
                }
            }
            if (cnt == k) ans = min(ans, r-l);
            if (a[l] <= k) {
                vis[a[l]]--;
                if (!vis[a[l]]) cnt--;
            }
            l++;
        }
        printf("Case %d: ", ++kase);
        printf(ans == INF ? "sequence nai\n" : "%d\n", ans);
    }

    return 0;
}







































































