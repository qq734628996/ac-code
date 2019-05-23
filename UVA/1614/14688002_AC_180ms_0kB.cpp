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
const int MAXN  = 1e5+5, INF = ~0U>>1, MOD = ~0U>>1;

int n, x, a[MAXN], b[MAXN], ans[MAXN];

bool cmp(const int& i, const int& j)
{
    return a[i] < a[j];
}

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    while (~scanf("%d", &n)) {
        REP(i,n) scanf("%d", &a[i]);
        REP(i,n) b[i] = i;
        sort(b, b+n, cmp);
        int cnt = 0;
        for (int i = n-1; i >= 0; i--) {
            if (cnt > 0) cnt -= a[b[i]], ans[b[i]] = 1;
            else cnt += a[b[i]], ans[b[i]] = -1;
        }
        if (cnt) puts("No");
        else {
            puts("Yes");
            SHOW1(ans, n)
        }
    }

    return 0;
}










































































