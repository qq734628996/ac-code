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
const double eps = 1e-14;
const int MAXN = 1e4+9, MAXM = 1e4+5;

int n,a[MAXN],b[MAXN],c[MAXN];
double f(double x)
{
    double ans=a[0]*x*x+b[0]*x+c[0];
    FOR(i,1,n-1) ans=max(ans, a[i]*x*x+b[i]*x+c[i]);
    return ans;
}

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    int T; scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        REP(i,n) scanf("%d%d%d", &a[i],&b[i],&c[i]);
        double l=0, r=1000;
        REP(i,100) {
            double m1=l+(r-l)/3;
            double m2=r-(r-l)/3;
            if (f(m1)<f(m2)) r=m2;
            else l=m1;
        }
        printf("%.4f\n", f(l));
    }

    return 0;
}




































