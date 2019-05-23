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
const int MAXN  = 2e5+5, INF = ~0U>>1, MOD = ~0U>>1;

int T, n, a[MAXN], f[MAXN], g[MAXN];
set<pii> S;

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    freopen("o.txt", "w", stdout);
#endif //LOCAL

    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        REP(i,n) scanf("%d", &a[i]);
        g[0] = 1;
        for (int i = 1; i < n; i++) {
            g[i] = a[i] > a[i-1] ? g[i-1]+1 : 1;
        }
        f[n-1] = 1;
        for (int i = n-2; i >= 0; i--) {
            f[i] = a[i] < a[i+1] ? f[i+1]+1 : 1;
        }
        int ans = 1;
        S.clear(); S.insert(pii(a[0], g[0]));
        for (int i = 1; i < n; i++) {
            auto it = S.lower_bound(pii(a[i], -1));
            if (it != S.begin()) ans = max(ans, f[i]+(--it)->second);
            it = S.lower_bound(pii(a[i], INF));
            if (it != S.begin()) {
                auto it1 = it;
                if ((--it1)->second >= g[i]) continue;
            }
            while (it != S.end() && it->second <= g[i]) S.erase(it++);
            S.insert(pii(a[i], g[i]));
        }
        printf("%d\n", ans);
    }

    return 0;
}











































































