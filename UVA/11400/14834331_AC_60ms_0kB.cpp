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
const int MAXN  = 1e3+5, INF = 0x3f3f3f3f, MOD = ~0U>>1;

int n, s[MAXN], dp[MAXN];
struct lamp {
    int V, K, C, L;
    bool operator<(const lamp& o) const { return V < o.V; }
} a[MAXN];

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    while (scanf("%d", &n), n) {
        FOR(i,1,n) scanf("%d%d%d%d", &a[i].V, &a[i].K, &a[i].C, &a[i].L);
        sort(a+1, a+1+n);
        FOR(i,1,n) s[i] = s[i-1] + a[i].L;
        memset(dp, 0x3f, sizeof(dp));
        dp[0] = 0;
        FOR(i,1,n)REP(j,i) {
            dp[i] = min(dp[i], dp[j] + (s[i]-s[j])*a[i].C + a[i].K);
        }
        printf("%d\n", dp[n]);
    }

    return 0;
}




















































































