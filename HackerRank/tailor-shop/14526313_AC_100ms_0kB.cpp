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

int n, p;
int a[MAXN], b[MAXN<<1];

int main()
{
#ifdef LOCAL
    //freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    scanf("%d%d", &n, &p);
    REP(i,n) scanf("%d", &a[i]);
    REP(i,n) b[(a[i]+p-1)/p]++;
    LL ans = 0;
    int cnt = 0, cnt1 = 0;
    for (int i = 0; ; i++) {
        if (cnt == n) break;
        if (b[i]) {
            ans += i;
            cnt++;
            cnt1 += (b[i]-1);
        } else if (cnt1) {
            ans += i;
            cnt++;
            cnt1--;
        }
    }
    cout << ans << endl;

    return 0;
}













































































