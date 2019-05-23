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
const int MAXN = 1e5+5, MAXM = 1e2+5, INF = 0x3f3f3f3f, MOD = 1e4+1;

int n, kase, vis[MAXN], prime[MAXN], tot, e[MAXN];

void getPrime(int n)
{
    int m = sqrt(n+0.5);
    for (int i = 2; i <= m; i++) if (!vis[i])
        for (int j = i*i; j <= n; j += i) vis[j] = 1;
    FOR(i,2,n) if (!vis[i]) prime[tot++] = i;
}

int add(int x)
{
    REP(i,tot) {
        while (x % prime[i] == 0) {
            x /= prime[i];
            e[i]++;
        }
        if (x == 1) break;
    }
    return x;
}

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    freopen("o.txt", "w", stdout);
#endif //LOCAL

    getPrime(1<<16);
    while (scanf("%d", &n), n) {
        if (n == 1) { printf("Case %d: 2\n", ++kase); continue; }
        memset(e, 0, sizeof(int) * tot);
        double ans = add(n);
        if (ans == 1) ans--;
        int cnt = ans == 0 ? 0 : 1;
        REP(i,tot) if (e[i]) {
            ans += pow(prime[i], e[i]);
            cnt++;
        }
        if (cnt == 1) ans += 1;
        printf("Case %d: %lld\n", ++kase, (LL)(ans+1e-8));
    }

    return 0;
}














































































