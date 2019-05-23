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
const int MAXN = 2e3+5, INF = 0x3f3f3f3f, MOD = 998244353;

int T, n, a[MAXN], b[MAXN], dp[MAXN];

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        FOR(i,1,n) scanf("%d", &a[i]);
        FOR(i,2,n) scanf("%d", &b[i]);
        dp[1] = a[1];
        FOR(i,2,n) dp[i] = min(dp[i-1]+a[i], dp[i-2]+b[i]);
        int ss = dp[n], mm = 0, hh = 8, sign = 0;
        mm = ss/60; ss %= 60;
        hh += mm/60; mm %= 60;
        if (hh > 12) hh -= 12, sign = 1;
        printf("%02d:%02d:%02d %s\n", hh, mm, ss, sign ? "pm" : "am");
    }

    return 0;
}




















































































