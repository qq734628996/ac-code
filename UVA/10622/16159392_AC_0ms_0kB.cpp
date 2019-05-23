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
const int MAXN = 5e4+5, MAXM = 1e5+5, INF = 0x3f3f3f3f, MOD = 1e8+7;

int vis[MAXN], prime[MAXN], tot, n, e[MAXN];
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
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a%b); }

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    sieve(MAXN-1);
    while (scanf("%d", &n), n) {
        memset(e, 0, sizeof(e));
        int ans = 0;
        REP(i,tot) {
            while (n%prime[i] == 0) {
                e[i]++;
                n /= prime[i];
            }
            if (e[i]) ans = !ans ? e[i] : gcd(ans, e[i]);
            if (n == 1 || n == -1) break;
        }
        if (n == -1) while (!(ans&1)) ans /= 2;
        if (n != 1 && n != -1) ans = 1;
        printf("%d\n", ans);
    }

    return 0;
}













































































