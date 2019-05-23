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
const int MAXN = 1e7+5, MAXM = 1e5+5, INF = 0x3f3f3f3f, MOD = 1e8+7;

int vis[MAXN], phifac[MAXN], n, m;
void sieve(int n)
{
    int m = sqrt(n+0.5);
    for (int i = 2; i <= m; i++) if (!vis[i])
        for (int j = i*i; j <= n; j += i) vis[j] = 1;
}
void getphifac(int n)
{
    sieve(n);
    phifac[1] = phifac[2] = 1;
    FOR(i,3,n) phifac[i] = (LL)phifac[i-1] * (vis[i] ? i : i-1) % MOD;
}

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    getphifac(MAXN-1);
    while (scanf("%d%d", &n, &m), n) {
        LL ans = phifac[m];
        FOR(i,m+1,n) ans = ans * i % MOD;
        printf("%lld\n", (ans-1+MOD)%MOD);
    }

    return 0;
}













































































