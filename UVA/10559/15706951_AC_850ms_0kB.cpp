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
const int MAXN = 2e2+5, MAXM = 3e3+5, INF = 0x3f3f3f3f, MOD = 1e9+7;

int T, n, a[MAXN], d[MAXN][MAXN][MAXN], vis[MAXN][MAXN][MAXN], kase;
int sqr(int x) { return x*x; }
int dp(int i, int j, int k)
{
    if (j < i) return k*k;
    int& ans = d[i][j][k];
    if (vis[i][j][k] == kase) return ans;
    vis[i][j][k] = kase;
    ans = 0;
    int x = j;
    while (i <= --x && a[x] == a[j]);
    ans = max(ans, dp(i,x,0) + sqr(j-x+k));
    int y = x;
    while (i <= --y) if (a[y] == a[j] && a[y+1] != a[j]) {
        ans = max(ans, dp(y+1,x,0) + dp(i,y,j-x+k));
    }
    return ans;
}

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    freopen("o.txt", "w", stdout);
#endif //LOCAL

    scanf("%d", &T);
    for (kase = 1; kase <= T; kase++) {
        scanf("%d", &n);
        REP(i,n) scanf("%d", &a[i]);
        printf("Case %d: %d\n", kase, dp(0,n-1,0));
    }

    return 0;
}


















































































