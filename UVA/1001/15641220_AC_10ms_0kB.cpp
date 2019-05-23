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
const int MAXN = 1e2+5, MAXM = 5e2+5, INF = 0x3f3f3f3f, MOD = 998244353;

int n, x[MAXN], y[MAXN], z[MAXN], r[MAXN], kase;
double g[MAXN][MAXN];
inline double dist(int a, int b, int c) { return sqrt(a*a + b*b + c*c); }
inline double dis(int i, int j) { return dist(x[i]-x[j],y[i]-y[j],z[i]-z[j]); }

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    while (scanf("%d", &n), n != -1) {
        FOR(i,1,n) scanf("%d%d%d%d", &x[i], &y[i], &z[i], &r[i]);
        n++;
        scanf("%d%d%d%d%d%d", &x[0], &y[0], &z[0], &x[n], &y[n], &z[n]);
        r[0] = r[n] = 0;
        FOR(i,0,n)FOR(j,0,n) {
            g[i][j] = max(0.0, dis(i,j)-r[i]-r[j]);
            g[i][j] *= 10;
        }
        FOR(k,0,n)FOR(i,0,n)FOR(j,0,n) g[i][j] = min(g[i][j], g[i][k]+g[k][j]);
        printf("Cheese %d: Travel time = %d sec\n", ++kase, (int)(g[0][n]+0.5+1e-9));
    }

    return 0;
}


















































































