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
const int MAXN = 1e3+5, MAXM = 5e3+5, INF = 0x3f3f3f3f, MOD = 1000007;

int C[MAXN][MAXN];

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    C[0][0]=1;
    FOR(i,0,500) {
        C[i][0]=C[i][i]=1;
        FOR(j,1,i-1) C[i][j]=(C[i-1][j-1]+C[i-1][j])%MOD;
    }
    int T; scanf("%d", &T);
    FOR(kase,1,T) {
        int n,m,k,sum=0;
        scanf("%d%d%d", &n,&m,&k);
        REP(i,(1<<4)) {
            int b=0, r=n, c=m;
            if (i>>0&1) r--, b++;
            if (i>>1&1) r--, b++;
            if (i>>2&1) c--, b++;
            if (i>>3&1) c--, b++;
            if (b&1) sum-=C[r*c][k];
            else sum+=C[r*c][k];
            sum%=MOD;
        }
        sum=(sum+MOD)%MOD;
        printf("Case %d: %d\n", kase,sum);
    }

    return 0;
}





































