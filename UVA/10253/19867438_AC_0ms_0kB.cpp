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
const int MAXN = 1e2+5, MAXM = 5e3+5, INF = 0x3f3f3f3f, MOD = 1000000000;

LL C(LL n, LL m)
{
    double ans=1;
    REP(i,m) ans*=n-i;
    REP(i,m) ans/=i+1;
    return (LL)(ans+0.5);
}
LL f[MAXN],d[MAXN][MAXN];

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    f[1]=1;
    int n=30;
    FOR(i,0,n) d[i][0]=1;
    FOR(i,1,n) d[i][1]=1;
    FOR(i,1,n) {
        FOR(j,2,n) {
            d[i][j]=0;
            FOR(p,0,j/i) d[i][j]+=C(f[i]+p-1,p)*d[i-1][j-p*i];
        }
        f[i+1]=d[i][i+1];
    }
    while (scanf("%d", &n)==1 && n) {
        printf("%lld\n", n==1 ? 1:2*f[n]);
    }

    return 0;
}




































