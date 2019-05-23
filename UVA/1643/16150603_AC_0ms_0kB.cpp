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
const int MAXN = 1e4+5, MAXM = 1e5+5, INF = 0x3f3f3f3f, MOD = 1e8+7;



int main()
{
#ifdef LOCAL
    freopen("i.txt", "r", stdin);
    freopen("o.txt", "w", stdout);
#endif //LOCAL

    const double PI = acos(-1);
    int n;
    double x1, y1, x2, y2;
    while (scanf("%d", &n), n) {
        scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
        double t1 = atan(y1/x1), t2 = atan(y2/x2);
        if (t1 < t2) swap(t1, t2);
        double t3 = t1-t2, t4 = t2+PI/4;
        double ans = 0, sum = 0;
        REP(i,n) { double x; scanf("%lf", &x); ans += sqrt(2)*x; sum += x*x/2; }
        ans = 0.5 * ans * ans/sin(t3)*sin(t4) * sin(PI-t3-t4) - sum;
        printf("%.3f\n", ans);
    }

    return 0;
}













































































