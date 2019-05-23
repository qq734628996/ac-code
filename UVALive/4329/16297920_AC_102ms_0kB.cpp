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
const int MAXN = 1e5+5, MAXM = 1e5+5, INF = 0x3f3f3f3f, MOD = 1000000007;

int n, a[MAXN], C[MAXN], c[MAXN], d[MAXN];
inline int lowbit(int x) { return x&-x; }
int sum(int x) { int ans = 0; while (0 < x) ans += C[x], x -= lowbit(x); return ans; }
void add(int x, int d) { while (x < MAXN) C[x] += d, x += lowbit(x); }

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    freopen("o.txt", "w", stdout);
#endif //LOCAL

    int T; scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        FOR(i,1,n) scanf("%d", &a[i]);
        FOR(i,1,n) { add(a[i],1); c[i] = sum(a[i]-1); }
        FOR(i,1,n) { add(a[i],-1); d[i] = sum(a[i]-1); }
        LL ans = 0;
        FOR(i,1,n) ans += c[i]*(n-i-d[i]) + (i-1-c[i])*d[i];
        printf("%lld\n", ans);
    }

    return 0;
}












































































