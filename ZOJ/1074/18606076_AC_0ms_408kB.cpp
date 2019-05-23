#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i = 0; i < n; i++)
#define PER(i,n) for(int i = n-1; i >= 0; i--)
#define FOR(i,l,r) for(int i = l; i <= r; i++)
#define ROF(i,l,r) for(int i = r; i >= l; i--)
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
const int MAXN = 1e2+5, MAXM = 1e4+5, INF = 0x3f3f3f3f, MOD = 998244353;

int n,a[123][123],dp[123][123],t[123];

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    while (~scanf("%d", &n)) {
        FOR(i,1,n)FOR(j,1,n) scanf("%d", &a[i][j]);
        FOR(i,1,n)FOR(j,1,n) dp[i][j]=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]+a[i][j];
        int ans=-INF;
        FOR(i1,1,n)FOR(i2,i1,n) {
            int ma=-INF,mi=0;
            FOR(j,1,n) {
                ma=max(ma,dp[i2][j]-dp[i1-1][j]-mi);
                mi=min(mi,dp[i2][j]-dp[i1-1][j]);
            }
            ans=max(ans,ma);
        }
        printf("%d\n", ans);
    }

    return 0;
}










































