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
const int MAXN  = 9e3+5, INF = 0x3f3f3f3f, MOD = ~0U>>1;

int T, n, t, dp[MAXN], cnt[MAXN], V, kase;

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    freopen("o.txt", "w", stdout);
#endif //LOCAL

    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n, &t);
        t = min(t, MAXN);
        memset(dp, 0, sizeof(dp));
        memset(cnt, 0, sizeof(cnt));
        REP(i,n) {
            scanf("%d", &V);
            PER(j,t)if(j >= V) {
                int v = dp[j-V] + V, num = cnt[j-V]+1;
                if (cnt[j] < num || (cnt[j] == num && dp[j] < v)) {
                    dp[j] = v; cnt[j] = num;
                }
            }
        }
        printf("Case %d: %d %d\n", ++kase, cnt[t-1]+1, dp[t-1]+678);
    }

    return 0;
}




















































































