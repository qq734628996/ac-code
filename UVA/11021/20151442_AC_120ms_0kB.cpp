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
const int INF = 0x3f3f3f3f, MOD = 100000007;
const int MAXN = 1e3+9, MAXM = 1e4+5;

int n,k,m;
double P[MAXN],f[MAXN];

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    int T; scanf("%d", &T);
    FOR(kase,1,T) {
        scanf("%d%d%d", &n,&k,&m);
        REP(i,n) scanf("%lf", &P[i]);
        f[1]=P[0];
        FOR(i,2,m) {
            f[i]=0;
            REP(j,n) f[i]+=P[j]*pow(f[i-1],j);
        }
        printf("Case #%d: %.7f\n", kase,pow(f[m],k));
    }

    return 0;
}




































