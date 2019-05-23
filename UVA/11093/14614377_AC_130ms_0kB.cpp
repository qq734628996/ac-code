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

int T, n, a[MAXN], b[MAXN], kase;

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        FOR(i,1,n) { scanf("%d", &a[i]); a[i+n] = a[i]; }
        FOR(i,1,n) { scanf("%d", &b[i]); b[i+n] = b[i]; }
        int ans = 1, i;
        while (ans <= n) {
            int cnt = 0;
            for (i = ans; i < ans+n; i++) {
                cnt += a[i];
                cnt -= b[i];
                if (cnt < 0) break;
            }
            if (i == ans+n) break;
            ans = i+1;
        }
        printf("Case %d: ", ++kase);
        if (ans > n) puts("Not possible");
        else printf("Possible from station %d\n", ans);
    }

    return 0;
}











































































