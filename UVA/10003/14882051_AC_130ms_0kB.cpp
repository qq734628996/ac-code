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
const int MAXN  = 1e3+5, INF = 0x3f3f3f3f, MOD = 998244353;

int len, n, a[55], d[55][55];

int dp(int i, int j)
{
    int& ans = d[i][j];
    if (ans != INF) return ans;
    if (i+1 == j) return ans = 0;
    FOR(k,i+1,j-1) ans = min(ans, dp(i, k)+dp(k, j));
    return ans += a[j]-a[i];
}

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    while (scanf("%d%d", &len, &n), len) {
        FOR(i,1,n) scanf("%d", &a[i]);
        memset(d, 0x3f, sizeof(d));
        a[n+1] = len;
        printf("The minimum cutting is %d.\n", dp(0, n+1));
    }

    return 0;
}




















































































