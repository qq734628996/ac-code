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
const int MAXN  = 1e3+5, INF = 0x3f3f3f3f, MOD = ~0U>>1;

int m, n, a[15][105], dp[15][105], nxt[15][105], bi;

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    while (~scanf("%d%d", &m, &n)) {
        REP(i,m)REP(j,n) scanf("%d", &a[i][j]);
        REP(i,m) dp[i][n-1] = a[i][n-1];
        PER(j,n-1)REP(i,m) {
            int r[3] = {(i+m-1)%m, i, (i+m+1)%m};
            sort(r, r+3);
            dp[i][j] = INF;
            REP(k,3) {
                int v = a[i][j] + dp[r[k]][j+1];
                if (v < dp[i][j]) { dp[i][j] = v; nxt[i][j] = r[k]; }
            }
        }
        int ans = INF;
        REP(i,m)if(dp[i][0] < ans) { ans = dp[i][0]; bi = i; }
        printf("%d", bi+1);
        for (int i = nxt[bi][0], j = 1; j < n; i = nxt[i][j], j++)
            printf(" %d", i+1);
        printf("\n%d\n", ans);
    }

    return 0;
}




















































































