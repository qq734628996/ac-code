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
const int MAXN = 1e3+5, MAXM = 1e5+5, INF = 0x3f3f3f3f, MOD = 1e9+7;

int a[MAXN], b[MAXN][MAXN], n, m;
bool jdg()
{
    FOR(i,1,m) if (a[i]) return false;
    return true;
}

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    while (~scanf("%d%d", &n, &m)) {
        memset(a, 0, sizeof(a));
        int L; scanf("%d", &L);
        REP(i,L) {
            int x; scanf("%d", &x);
            a[x] = 1;
        }
        REP(i,n) {
            scanf("%d", &b[i][0]);
            FOR(j,1,b[i][0]) scanf("%d", &b[i][j]);
        }
        int ans = 0;
        REP(i,n) {
            if (jdg()) break;
            ans++;
            FOR(j,1,b[i][0]) a[b[i][j]] = !a[b[i][j]];
        }
        if (ans == n)REP(i,n) {
            if (jdg()) break;
            ans++;
            FOR(j,1,b[i][0]) a[b[i][j]] = !a[b[i][j]];
        }
        if (ans == 2*n) ans = -1;
        printf("%d\n", ans);
    }

    return 0;
}













































































