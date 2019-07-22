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

double a;
double F(double x)
{
    return sqrt(1+4*a*a*x*x);
}
double simpson(double a, double b)
{
    double c=(a+b)/2;
    return (F(a)+4*F(c)+F(b))*(b-a)/6;
}
double asr(double a, double b, double eps, double A)
{
    double c=(a+b)/2;
    double L=simpson(a,c), R=simpson(c,b);
    if (fabs(L+R-A)<=15*eps) return L+R+(L+R-A)/15;
    return asr(a,c,eps/2,L) + asr(c,b,eps/2,R);
}
double asr(double a, double b, double eps)
{
    return asr(a,b,eps,simpson(a,b));
}
double p(double w, double h)
{
    a=4*h/w/w;
    return asr(0,w/2,1e-5)*2;
}

int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL

    int T; scanf("%d", &T);
    FOR(kase,1,T) {
        int D,H,B,L; scanf("%d%d%d%d", &D,&H,&B,&L);
        int n=(B+D-1)/D;
        double D1=(double)B/n;
        double L1=(double)L/n;
        double l=0, r=H;
        while (r-l>1e-5) {
            double m=(l+r)/2;
            if (p(D1,m)<L1) l=m;
            else r=m;
        }
        printf("Case %d:\n%.2f\n", kase,H-l);
        if (kase!=T) puts("");
    }

    return 0;
}




































