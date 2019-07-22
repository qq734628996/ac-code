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
const double EPS = 1e-14;
const int MAXN = 1e5+9, MAXM = 1e4+5;

ULL fac[22],a[22],cnt[11],d[22];

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    freopen("o.txt", "w", stdout);
#endif //LOCAL

    fac[0]=1;
    FOR(i,1,12) fac[i]=fac[i-1]*i;
    d[1]=1;
    FOR(i,2,12) d[i]=d[i-1]*10+1;
    int n;
    while (scanf("%d", &n)==1 && n) {
        memset(cnt,0,sizeof(cnt));
        REP(i,n) scanf("%llu", &a[i]), cnt[a[i]]++;
        ULL ans=0;
        REP(i,10) if (cnt[i]) {
            ULL t=1;
            REP(j,10) if (cnt[j]) {
                if (i==j) {
                    if (cnt[j]>=2) t*=fac[cnt[j]-1];
                } else t*=fac[cnt[j]];
            }
            ans+=fac[n-1]/t*i*d[n];
        }
        printf("%llu\n", ans);
    }

    return 0;
}



































