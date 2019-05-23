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
const int MAXN  = 1e6+5, INF = ~0U>>1, MOD = ~0U>>1;

int n, x, maa, mab, a[MAXN], b[MAXN], ans[2];

int main()
{
#ifdef LOCAL
    //freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    scanf("%d", &n);
    REP(i,n) { scanf("%d", &x); maa = max(maa, x); a[x] = 1; }
    REP(i,n) { scanf("%d", &x); mab = max(mab, x); b[x] = 1; }
    int ma = min(maa, mab);
    int mam = max(maa, mab);
    for (int i = ma; i >= 1; i--) {
        ans[0] = ans[1] = 0;
        for (int j = 1; ; j++) {
            x = i*j;
            if (x > ma && (!ans[0] && !ans[1])) break;
            if (x > mam) break;
            if (a[x]) ans[0] = x;
            if (b[x]) ans[1] = x;
        }
        if (ans[0] && ans[1]) { cout << (LL)ans[0]+ans[1] << endl; break; }
    }

    return 0;
}












































































