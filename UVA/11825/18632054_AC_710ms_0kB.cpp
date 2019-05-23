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
typedef pair<int, int> pii;
const int MAXN = 1e5+5, MAXM = 1e4+5, INF = 0x3f3f3f3f, MOD = 998244353;

int n,a[22],d[1<<20],f[1<<20],kase;

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    while (scanf("%d", &n)==1 && n) {
        REP(i,n) {
            int m; scanf("%d", &m);
            a[i]=(1<<i);
            REP(j,m) {
                int x; scanf("%d", &x);
                a[i]|=(1<<x);
            }
        }
        REP(S,(1<<n)) {
            f[S]=0;
            REP(i,n) if (S&(1<<i)) f[S]|=a[i];
        }
        d[0]=0;
        int tot=(1<<n)-1;
        for (int S=1; S<(1<<n); S++) {
            d[S]=0;
            for (int S0=S; S0; S0=(S0-1)&S) {
                if (f[S0]==tot) d[S]=max(d[S],d[S^S0]+1);
            }
        }
        printf("Case %d: %d\n", ++kase,d[tot]);
    }

    return 0;
}










































