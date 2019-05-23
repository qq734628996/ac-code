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
const int MAXN = 2e3+5, MAXM = 3e1+5, INF = 0x3f3f3f3f, MOD = 1e9+7;

int T, n, k, is[12][MAXN];
LL d[500][MAXN];

int jdg(int x, int k)
{
    int rev = 0, tmp = x;
    REP(i,k) {
        rev <<= 1;
        rev |= (tmp&1);
        tmp >>= 1;
    }
    return rev == x;
}

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    freopen("o.txt", "w", stdout);
#endif //LOCAL

    FOR(i,1,11)REP(j,(1<<i)) is[i][j] = !jdg(j,i);
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n, &k);
        if (n < k) { printf("%d\n", 1<<n); continue; }
        REP(i,(1<<k)) d[k][i] = is[k][i];
        int x = (1<<k)-1;
        FOR(i,k+1,n)REP(j,(1<<k)) {
            d[i][j] = 0;
            if (is[k][j]) {
                int y = (j<<1);
                if (is[k+1][y] && d[i-1][y&x]) d[i][j] += d[i-1][y&x];
                y ^= 1;
                if (is[k+1][y] && d[i-1][y&x]) d[i][j] += d[i-1][y&x];
                d[i][j] %= MOD;
            }
        }
        LL ans = 0;
        REP(i,(1<<k)) ans += d[n][i];
        ans %= MOD;
        printf("%lld\n", ans);
    }

    return 0;
}














































































