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
const int MAXN = 1e6+5, MAXM = 1e5+5, INF = 0x3f3f3f3f, MOD = 1e8+7;

int vis[MAXN], prime[MAXN], tot;
void sieve(int n)
{
    FOR(i,2,n) {
        if (!vis[i]) prime[tot++] = i;
        REP(j,tot) {
            if (i*prime[j] > n) break;
            vis[i*prime[j]] = 1;
            if (i%prime[j] == 0) break;
        }
    }
}

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    sieve(1e6);
    int T; scanf("%d", &T);
    while (T--) {
        LL L, R; scanf("%lld%lld", &L, &R);
        LL ans = 0;
        REP(i,tot) {
            LL x = (LL)prime[i]*prime[i];
            if (x > R) break;
            while (x <= R) {
                if (x >= L) ans++;
                x *= prime[i];
            }
        }
        printf("%lld\n", ans);
    }

    return 0;
}













































































