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
const int MAXN = 2e1+5, MAXM = 3e3+5, INF = 0x3f3f3f3f, MOD = 1e9+7;

int m, n, K, a[MAXN][MAXN], kase;
int d[MAXN][MAXN][MAXN][MAXN], vis[MAXN][MAXN][MAXN][MAXN];

int dp(int x1, int y1, int x2, int y2)
{
    int& ans = d[x1][y1][x2][y2];
    if (vis[x1][y1][x2][y2] == kase) return ans;
    else vis[x1][y1][x2][y2] = kase;
    int cnt = 0;
    FOR(i,x1,x2)FOR(j,y1,y2) if (a[i][j] && ++cnt > 1) break;
    ans = INF;
    if (cnt > 1) {
        int c1 = y2-y1+1, c2 = x2-x1+1;
        FOR(i,x1+1,x2) ans = min(ans, dp(x1,y1,i-1,y2) + dp(i,y1,x2,y2) + c1);
        FOR(j,y1+1,y2) ans = min(ans, dp(x1,y1,x2,j-1) + dp(x1,j,x2,y2) + c2);
    }
    if (cnt == 1) ans = 0;
    return ans;
}

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    freopen("o.txt", "w", stdout);
#endif //LOCAL

    while (~scanf("%d%d%d", &m, &n, &K)) {
        printf("Case %d: ", ++kase);
        memset(a, 0, sizeof(a));
        REP(i,K) {
            int x, y; scanf("%d%d", &x, &y);
            a[x][y] = 1;
        }
        printf("%d\n", dp(1,1,m,n));
    }

    return 0;
}


















































































