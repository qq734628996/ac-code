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
const int MAXN  = 1e3+5, INF = 0x3f3f3f3f, MOD = ~0U>>1;

int n, x, y;
vector<pii> p;
double dist[MAXN][MAXN], d[MAXN][MAXN];

double dp(int i, int j)
{
    if (d[i][j]) return d[i][j];
    if (i == n-2) return d[i][j] = dist[n-2][n-1] + dist[j][n-1];
    return d[i][j] = min(dp(i+1, j) + dist[i][i+1], dp(i+1, i) + dist[j][i+1]);
}

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    while (~scanf("%d", &n)) {
        p.clear();
        REP(i,n) scanf("%d%d", &x, &y), p.pb(pii(x, y));
        REP(i,n)FOR(j,i+1,n-1) dist[i][j] = hypot(p[i].fi-p[j].fi, p[i].se-p[j].se);
        memset(d, 0, sizeof(d));
        printf("%.2f\n", dist[0][1] + dp(1, 0));
    }

    return 0;
}




















































































