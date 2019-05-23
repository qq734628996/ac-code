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
const int MAXN = 1e4+5, MAXM = 1e5+5, INF = 0x3f3f3f3f, MOD = 10056;

int C[MAXN][MAXN], f[MAXN], n;

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    FOR(i,0,1000) {
        C[i][0] = 1;
        FOR(j,1,i) C[i][j] = (C[i-1][j-1] + C[i-1][j]) % MOD;
    }
    f[0] = 1;
    FOR(i,1,1000) {
        FOR(j,1,i) f[i] += (C[i][j]*f[i-j])%MOD;
        f[i] %= MOD;
    }
    int T; scanf("%d", &T);
    FOR(kase,1,T) {
        scanf("%d", &n);
        printf("Case %d: %d\n", kase, f[n]);
    }

    return 0;
}













































































