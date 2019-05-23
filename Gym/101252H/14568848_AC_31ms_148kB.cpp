#include <bits/stdc++.h>
using namespace std;

#define REP(i,n) for(int i = 0; i < n; i++)
#define FOR(i,l,r) for(int i = l; i <= r; i++)
#define TR(e,x) for(auto e = x.begin(); e != x.end(); e++)
#define DEBUG(x) cout << #x << "=" << x << endl;
#define SHOW1(A,n) { REP(i,n-1) printf("%d ", A[i]); printf("%d\n", A[n-1]); }
#define SHOW2(A,m,n) { REP(i,m) { REP(j,n-1) printf("%d ", A[i][j]); printf("%d\n", A[i][n-1]); } }
#define PB push_back
#define ALL(x) x.begin(),x.end()
#define SZ(x) (int)((x).size())
typedef long long LL;
typedef pair<int, int> pii;
const int MAXN  = 1e2+5, INF = ~0U>>1, MOD = ~0U>>1;

int s, m, p;
const double eps = 1e-7;
double a[MAXN], b[MAXN];

int main()
{
#ifdef LOCAL
    //freopen("i.txt", "r", stdin);
    //freopen("o.txt", "w", stdout);
#endif //LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    scanf("%d%d%d", &s, &m, &p);
    double l = 0, r = s*3;
    while (r-l > eps) {
        double mi = (l+r)/2;
        double sum = s;
        FOR(i,1,m) {
            sum -= b[i-1];
            a[i] = sum * p / 100.0;
            b[i] = mi - a[i];
        }
        if (sum - b[m] > 0) l = mi;
        else r = mi;
    }
    printf("%.7f\n", (r+l)/2);

    return 0;
}











































































