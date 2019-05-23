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
const int MAXN = 2e3+5, INF = 0x3f3f3f3f, MOD = 998244353;

int T, V, n, c[MAXN], a[MAXN], b[MAXN], dp[MAXN], vis[MAXN];

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &V, &n);
        REP(i,n) scanf("%d%d%d", &c[i], &a[i], &b[i]);
        memset(dp, 0, sizeof(int) * (V+1));
        REP(i,n) {
            memset(vis, 0, sizeof(int) * (V+1));
            ROF(j,c[i],V) if (dp[j-c[i]] + a[i] + b[i] > dp[j]) {
                dp[j] = dp[j-c[i]] + a[i] + b[i];
                vis[j] = 1;
            }
            FOR(j,2*c[i],V) if (vis[j-c[i]] && dp[j-c[i]] + a[i] > dp[j]) {
                dp[j] = dp[j-c[i]] + a[i];
                vis[j] = 1;
            }
        }
        printf("%d\n", dp[V]);
    }

    return 0;
}




















































































