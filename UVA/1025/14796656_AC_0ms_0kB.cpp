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
const int MAXN  = 1e5+5, INF = 0x3f3f3f3f, MOD = ~0U>>1;

int n, T, t[55], m[2], M[2][55], s[2][55], has[2][205][55], dp[205][55], kase;

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    while (scanf("%d", &n), n) {
        scanf("%d", &T);
        FOR(i,1,n-1) scanf("%d", &t[i]);
        REP(i,2) {
            scanf("%d", &m[i]);
            REP(j,m[i]) scanf("%d", &M[i][j]);
        }

        s[0][1] = s[1][n] = 0;
        FOR(i,2,n) s[0][i] = s[0][i-1] + t[i-1];
        ROF(i,1,n-1) s[1][i] = s[1][i+1] + t[i];
        memset(has, 0, sizeof(has));
        REP(i,m[0])FOR(j,1,n)if(M[0][i] + s[0][j] <= T)
            has[0][M[0][i] + s[0][j]][j] = 1;
        REP(i,m[1])ROF(j,1,n)if(M[1][i] + s[1][j] <= T)
            has[1][M[1][i] + s[1][j]][j] = 1;

        FOR(i,1,n-1)dp[T][i] = INF; dp[T][n] = 0;
        PER(i,T)FOR(j,1,n) {
            dp[i][j] = dp[i+1][j] + 1;
            if (j < n && has[0][i][j] && i+t[j] <= T)
                dp[i][j] = min(dp[i][j], dp[i+t[j]][j+1]); //to right
            if (j > 1 && has[1][i][j] && i+t[j-1] <= T)
                dp[i][j] = min(dp[i][j], dp[i+t[j-1]][j-1]); //to left
        }

        printf("Case Number %d: ", ++kase);
        if (dp[0][1] >= INF) puts("impossible");
        else printf("%d\n", dp[0][1]);
    }

    return 0;
}




















































































