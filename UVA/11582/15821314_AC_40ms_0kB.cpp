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
const int MAXN = 1e3+5, MAXM = 1e2+5, INF = 0x3f3f3f3f, MOD = 1e9+7;

int T, n, f[MAXN*MAXN], cnt;
typedef unsigned long long ull;
ull a, b;


ull powMod(ull x, ull e)
{
    ull ans = 1;
    while (e) {
        if (e&1) ans = (ans * x) % cnt;
        x = (x*x)%cnt;
        e >>= 1;
    }
    return ans;
}

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    freopen("o.txt", "w", stdout);
#endif //LOCAL

    REP(i,2) f[i] = i;
    scanf("%d", &T);
    while (T--) {
        scanf("%llu%llu%d", &a, &b, &n);
        if (n == 1) { puts("0"); continue; }
        for (int i = 2; ; i++) {
            f[i] = (f[i-1]+f[i-2])%n;
            if (!f[i-1] && f[i] == 1) { cnt = i-1; break; }
        }
        printf("%d\n", f[(int)powMod(a%cnt, b)]);
    }

    return 0;
}














































































