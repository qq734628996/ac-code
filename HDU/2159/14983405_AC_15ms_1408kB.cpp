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
const int MAXN = 105, INF = 0x3f3f3f3f, MOD = 998244353;

int n, m, k, s, c[MAXN], w[MAXN], dp[MAXN][MAXN];

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    while (~scanf("%d%d%d%d", &n, &m, &k, &s)) {
        REP(i,k) scanf("%d%d", &w[i], &c[i]);
        memset(dp, 0, sizeof(dp));
        FOR(j,1,s)REP(i,k)FOR(u,c[i],m)dp[u][j] = max(dp[u][j], dp[u-c[i]][j-1]+w[i]);
        int i = m;
        for ( ; i>=0 && dp[i][s] >= n; i--);
        if (i == m) puts("-1");
        else printf("%d\n", m-(i+1));
    }

    return 0;
}




















































































