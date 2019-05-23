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
const int MAXN = 2e6+5, MAXM = 1e5+5, INF = 0x3f3f3f3f, MOD = 1e9+7;

int f[35], g[35], n;

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    REP(i,3) g[i] = 1<<i;
    FOR(i,3,30) {
        f[i] = 1<<(i-3);
        FOR(j,2,i-2) f[i] += g[j-2]*(1<<(i-j-2));
        g[i] = (1<<i) - f[i];
    }
    while (scanf("%d", &n), n) printf("%d\n", f[n]);

    return 0;
}













































































