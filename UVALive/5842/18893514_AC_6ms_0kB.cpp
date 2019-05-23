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
const int MAXN = 1e4+5, MAXM = 1e4+5, INF = 0x3f3f3f3f, MOD = 998244353;

int n,K,a[5][MAXN],ma[32],f[32][5];
int solve()
{
    if (K>=5) {
        int sum=0;
        REP(i,5) sum+=*max_element(a[i],a[i]+n);
        return sum;
    }
    memset(ma,0,sizeof(ma));
    FOR(j,1,31) REP(i,n) {
        int sum=0;
        REP(k,5)if (j>>k&1) sum+=a[k][i];
        ma[j]=max(ma[j],sum);
    }
    memset(f,-1,sizeof(f));
    f[0][0]=0;
    FOR(i,1,31)FOR(j,1,K) {
        for (int k=i; k; k=(k-1)&i) {
            f[i][j]=max(f[i][j], f[i^k][j-1]+ma[k]);
        }
    }
    return f[31][K];
}

int main()
{
#ifdef LOCAL
    //freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    int T; scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n,&K);
        REP(i,n)REP(j,5) scanf("%d", &a[j][i]);
        printf("%d\n", solve());
    }

    return 0;
}









































