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
const int MAXN = 1e6+5, INF = 0x3f3f3f3f, MOD = 998244353;

int n, h[32][3], d[32][3], kase;

int dp(int u, int v)
{
    int& ans = d[u][v];
    if (ans) return ans;
    int a = h[u][(v+1)%3], b = h[u][(v+2)%3];
    if (b < a) swap(a, b);
    REP(i,n)REP(j,3)FOR(k,j+1,2) {
        if (a < h[i][j] && b < h[i][k]) {
            ans = max(ans, dp(i, 3-j-k));
        }
    }
    return ans += h[u][v];
}

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    while (scanf("%d", &n), n) {
        REP(i,n) {
            REP(j,3) scanf("%d", &h[i][j]);
            sort(h[i], h[i]+3);
        }
        memset(d, 0, sizeof(d));
        int ans = 0;
        REP(i,n)REP(j,3) ans = max(ans, dp(i,j));
        printf("Case %d: maximum height = %d\n", ++kase, ans);
    }

    return 0;
}




















































































