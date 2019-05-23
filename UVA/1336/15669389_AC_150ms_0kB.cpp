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
const int MAXN = 1e3+5, MAXM = 1e6+5, INF = 0x3f3f3f3f, MOD = 998244353;

int n, st, s[MAXN], vis[MAXN][MAXN][2], kase;
double d[MAXN][MAXN][2], v;
struct node {
    int x, c, d;
    bool operator<(const node& o) const { return x < o.x; }
} a[MAXN];

double dp(int i, int j, int k)
{
    if (1 < i && a[i-1].x > st) return 1e18;
    if (j < n && a[j+1].x < st) return 1e18;
    if (i == j) return a[i].c + abs(st-a[i].x)/v*s[n];
    double& ans = d[i][j][k];
    if (vis[i][j][k] == kase) return ans;
    vis[i][j][k] = kase;
    ans = 1e18;
    if (k) {
        REP(l,2) {
            int x = l ? a[j-1].x : a[i].x;
            double t = abs(a[j].x - x) / v;
            ans = min(ans, dp(i,j-1,l) + a[j].c + t*(s[i-1]+s[n]-s[j-1]));
        }
    } else {
        REP(l,2) {
            int x = l ? a[j].x : a[i+1].x;
            double t = abs(a[i].x - x) / v;
            ans = min(ans, dp(i+1,j,l) + a[i].c + t*(s[i]+s[n]-s[j]));
        }
    }
    return ans;
}

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    while (~scanf("%d%lf%d", &n, &v, &st) && (n+(int)v+st)) {
        kase++;
        FOR(i,1,n) scanf("%d%d%d", &a[i].x, &a[i].c, &a[i].d);
        sort(a+1, a+1+n);
        FOR(i,1,n) s[i] = s[i-1] + a[i].d;
        printf("%d\n", (int)min(dp(1,n,0), dp(1,n,1)));
    }

    return 0;
}


















































































