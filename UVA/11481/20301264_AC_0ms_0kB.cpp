#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i = 0; i < n; i++)
#define PER(i,n) for(int i = n-1; i >= 0; i--)
#define FOR(i,l,r) for(int i = l; i <= r; i++)
#define ROF(i,l,r) for(int i = r; i >= l; i--)
#define DEBUG(x) cout << #x << "=" << x << endl;
#define SHOW1(A,n) { REP(i,n-1) printf("%d ", A[i]); printf("%d\n", A[n-1]); }
#define SHOW2(A,m,n) { REP(i,m) { REP(j,n-1) printf("%d ", A[i][j]); printf("%d\n", A[i][n-1]); } }
#define pb push_back
#define fi first
#define se second
#define ALL(x) x.begin(),x.end()
#define SZ(x) (int)((x).size())
typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;
const int INF = 0x3f3f3f3f, MOD = 1000000007;
const double PI = acos(-1), EPS = 1e-15;
const int MAXN = 1e3+9, MAXM = 3e3+9;

LL f[MAXN][MAXN],g[MAXN][MAXN],C[MAXN][MAXN];

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    freopen("o.txt", "w", stdout);
#endif //LOCAL

    f[0][0]=1;
    FOR(i,1,1000) f[0][i]=f[0][i-1]*i%MOD;
    FOR(i,0,1000) f[1][i]=i*f[0][i]%MOD;
    FOR(i,2,1000)FOR(j,0,1000) f[i][j]=((i+j-1)*f[i-1][j]+(i-1)*f[i-2][j])%MOD;
    C[0][0]=1;
    FOR(i,1,1000) {
        C[i][0]=1;
        FOR(j,1,i) C[i][j]=(C[i-1][j-1]+C[i-1][j])%MOD;
    }
    int T; scanf("%d", &T);
    FOR(kase,1,T) {
        int n,m,k; scanf("%d%d%d", &n,&m,&k);
        printf("Case %d: %lld\n", kase,C[m][k]*f[m-k][n-m]%MOD);
    }

    return 0;
}

































