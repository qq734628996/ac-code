#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i = 0; i < n; i++)
#define FOR(i,l,r) for(int i = l; i <= r; i++)
#define TR(e,x) for(auto e = x.begin(); e != x.end(); e++)
#define DEBUG(x) cout << #x << "=" << x << endl;
#define SHOW1(A,n) { REP(i,n-1) printf("%d ", A[i]); printf("%d\n", A[n-1]); }
#define SHOW2(A,m,n) { REP(i,m) { REP(j,n-1) printf("%d ", A[i][j]); printf("%d\n", A[i][n-1]); } }
#define PB push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) (int)((x).size())
typedef long long LL;
typedef pair<int, int> pii;
const int MAXN  = 50, INF = ~0U>>1, MOD = ~0U>>1;

int n, m, a[MAXN][MAXN];

int main()
{
#ifdef LOCAL
    //freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    while (scanf("%d", &n), n) {
        m = 0;
        REP(i,50)REP(j,50) a[i][j] = i==j ? 0:1e9;
        REP(i,n) {
            int x,y,z; scanf("%d%d%d", &x,&y,&z);
            a[x][y] = a[y][x] = z;
            m = max(m, x); m = max(m, y);
        }
        m++;
        REP(k,m)REP(i,m)REP(j,m) a[i][j] = min(a[i][j], a[i][k]+a[k][j]);
        int ans = 0, sum = INF;
        REP(i,m) {
            int cnt = 0;
            REP(j,m) cnt += a[i][j];
            if (cnt < sum) sum = cnt, ans = i;
        }
        printf("%d %d\n", ans, sum);
    }

    return 0;
}











































































