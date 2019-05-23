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
const int MAXN = 1e4+5, INF = 0x3f3f3f3f, MOD = 998244353;

int T, n, V, c[MAXN];
double dp[MAXN], ma, w[MAXN];

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    scanf("%d", &T);
    while (T--) {
        scanf("%lf%d", &ma, &n); ma = 1.0-ma;
        V = 0;
        REP(i,n) scanf("%d%lf", &c[i], &w[i]), w[i] = 1-w[i] , V += c[i];
        dp[0] = 1.0; FOR(i,1,V) dp[i] = 0.0;
        REP(i,n)ROF(j,c[i],V) dp[j] = max(dp[j], dp[j-c[i]]*w[i]);
        int i = V;
        for (; i >= 0; i--) if (dp[i] > ma) break;
        printf("%d\n", i);
    }

    return 0;
}




















































































