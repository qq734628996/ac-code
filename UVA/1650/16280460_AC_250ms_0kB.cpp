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
const int MAXN = 1e3+5, MAXM = 1e5+5, INF = 0x3f3f3f3f, MOD = 1000000007;

LL d[MAXN][MAXN];
int n, vis[MAXN][MAXN], kase;
char s[MAXN];

LL dp(int i, int j)
{
    if (i > n) return 1;
    LL& ans = d[i][j];
    if (vis[i][j] == kase) return ans;
    vis[i][j] = kase;
    ans = 0;
    if (!j) {
        FOR(k,1,i+1) ans += dp(i+1,k);
    } else if (s[i] == 'I') {
        if (j == 1) ans += dp(i+1,j);
        else ans += dp(i,j-1) + dp(i+1,j);
    } else if (s[i] == 'D') {
        if (j == i) ans += dp(i+1,j+1);
        else ans += dp(i,j+1) + dp(i+1,j+1);
    } else {
        ans += dp(i,0);
    }
    return ans %= MOD;
}

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    while (~scanf("%s", s+1)) {
        kase++;
        n = strlen(s+1);
        printf("%lld\n", dp(1,1));
    }

    return 0;
}












































































