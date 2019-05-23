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
const int MAXN = 1e2+5, MAXM = 3e1+5, INF = 0x3f3f3f3f, MOD = 1e9+7;

int n, m, a[MAXM], d[MAXN][MAXM], c[MAXN][MAXM];

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    while (scanf("%d%d", &n, &m), n) {
        FOR(i,1,m) scanf("%d", &a[i]);
        FOR(j,0,m) d[0][j] = INF;
        FOR(i,1,n)FOR(j,1,m) {
            d[i][j] = d[i][j-1];
            FOR(k,1,min(i,a[j])) {
                d[i][j] = max(d[i][j], min(d[i-k][j-1], a[j]/k));
            }
        }
        FOR(i,1,n) c[i][0] = INF;
        FOR(i,1,n)FOR(j,1,m) {
            c[i][j] = c[i][j-1];
            FOR(k,1,min(i,a[j])) if (a[j]/k >= d[n][m]) {
                c[i][j] = min(c[i][j], c[i-k][j-1] + a[j]);
            }
        }
        if (!d[n][m]) c[n][m] = 0;
        printf("%d %d\n", d[n][m], c[n][m]);
    }

    return 0;
}















































































